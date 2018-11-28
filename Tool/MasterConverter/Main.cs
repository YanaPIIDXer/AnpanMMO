using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace MasterConverter
{
	public partial class Main : Form
	{

		/// <summary>
		/// エクセルファイルを格納するパス
		/// </summary>
		private static readonly string ExcelFilePath = "MasterData";

		/// <summary>
		/// ソースディレクトリ設定ファイル名.
		/// </summary>
		private static readonly string SourceDirectorySettingFileName = "SourceDirectory.ini";

		/// <summary>
		/// ゲームサーバソースディレクトリ
		/// </summary>
		private string GameServerSourceDirectory = "";

		/// <summary>
		/// クライアントソースディレクトリ
		/// </summary>
		private string ClientSourceDirectory = "";

		/// <summary>
		/// ワードチェックサーバディレクトリ
		/// </summary>
		private string WordCheckServerDirectory = "";
		
		public Main()
		{
			InitializeComponent();
			LoadSourceDirectorySetting();
			if(!Directory.Exists(Config.TransportTargetsPath))
			{
				Directory.CreateDirectory(Config.TransportTargetsPath);
			}
			ReloadTransportTargetList();
		}

		// 出力ボタンが押された
		private void OutputButton_Click(object sender, EventArgs e)
		{
			if(TransportTargetList.SelectedIndex == -1)
			{
				MessageBox.Show("転送先を選択してください。");
				return;
			}

			TransportTargetReader TargetReader = new TransportTargetReader(TransportTargetList.SelectedItem.ToString());
			if(!TargetReader.Read())
			{
				MessageBox.Show("転送先データの読み込みに失敗しました。");
				return;
			}
			string Host = TargetReader.Host;
			string UserName = TargetReader.UserName;
			string Password = TargetReader.Password;
			string BinaryHost = TargetReader.BinaryHost;
			string BinaryPath = TargetReader.BinaryPath;

			// .sql生成.
			if (!GenerateSQLFiles())
			{
				DeleteTemporaryDirectory();
				return;
			}

			// マスタ展開.
			if (!ExpandMaster(Host, UserName, Password))
			{
				DeleteTemporaryDirectory();
				return;
			}

			// バイナリ転送.
			if(!TransportBinaryFiles(BinaryHost, UserName, Password, BinaryPath))
			{
				DeleteTemporaryDirectory();
				return;
			}

			// 後片付け
			DeleteTemporaryDirectory();
			
			MessageBox.Show("出力しました。");
		}

		/// <summary>
		/// ソースディレクトリ設定ファイル読み込み
		/// </summary>
		private void LoadSourceDirectorySetting()
		{
			if(!File.Exists(SourceDirectorySettingFileName))
			{
				using (StreamWriter Writer = new StreamWriter(SourceDirectorySettingFileName))
				{
					Writer.WriteLine("../Server/AnpanMMOServer/Master");
					Writer.WriteLine("../Client/AnpanMMO/Source/AnpanMMO/Master");
					Writer.WriteLine("../Server/WordCheckServer/Master");
				}
			}

			using (StreamReader Reader = new StreamReader(SourceDirectorySettingFileName))
			{
				GameServerSourceDirectory = Reader.ReadLine();
				ClientSourceDirectory = Reader.ReadLine();
				WordCheckServerDirectory = Reader.ReadLine();
			}
		}

		/// <summary>
		/// .sqlファイルの生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		private bool GenerateSQLFiles()
		{
			// ディレクトリ生成.
			if(!Directory.Exists(Config.TemporaryDirectoryPath))
			{
				Directory.CreateDirectory(Config.TemporaryDirectoryPath);
			}

			string[] Files = Directory.GetFiles(ExcelFilePath);
			foreach (var TargetFilePath in Files)
			{
				if (Path.GetExtension(TargetFilePath) != ".xlsx") { continue; }
				Console.Write(TargetFilePath + "の展開中...");
				ExcelParser Parser = new ExcelParser(TargetFilePath);
				if (!Parser.Load())
				{
					MessageBox.Show("Excelファイルの解析に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");

				// オートキー
				if (Parser.Master.IsAutoKey)
				{
					Parser.Master.GenerateAutoKey();
				}

				string MasterName = Path.GetFileNameWithoutExtension(TargetFilePath);
				string FileName = MasterName + ".sql";
				string FilePath = Config.TemporaryDirectoryPath + "\\" + FileName;
				Console.Write(FilePath + "の生成中...");

				SQLGenerator SQLGen = new SQLGenerator(FilePath, Parser.Master.GetColumns());
				if (!SQLGen.Generate())
				{
					MessageBox.Show("SQLファイルの生成に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");

				Console.Write("サーバソースの生成中...");

				string TargetDirectory = GameServerSourceDirectory;
				if(Parser.Master.IsForWordCheckServer)
				{
					TargetDirectory = WordCheckServerDirectory;
				}
				ServerSourceGenerator ServerSource = new ServerSourceGenerator(TargetDirectory, Parser.Master);
				if (!ServerSource.Generate())
				{
					MessageBox.Show("サーバソースの生成に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");

				if (!Parser.Master.IsServerOnly)
				{
					Console.Write("クライアントソースの生成中...");

					ClientSourceGenerator ClientSource = new ClientSourceGenerator(ClientSourceDirectory, Parser.Master);
					if (!ClientSource.Generate())
					{
						MessageBox.Show("クライアントソースの生成に失敗しました。");
						Console.WriteLine("失敗。");
						return false;
					}

					Console.WriteLine("完了。");

					Console.Write("バイナリデータ生成中...");
					BinaryGenerator BinGenerator = new BinaryGenerator(MasterName, Parser.Master.GetColumns());
					if (!BinGenerator.Generate())
					{
						MessageBox.Show("バイナリデータの生成に失敗しました。");
						Console.WriteLine("失敗。");
						return false;
					}
					Console.WriteLine("完了。");
				}
			}

			Console.Write("バージョンファイル生成中...");
			string[] AllFile = Directory.GetFiles(Config.TemporaryDirectoryPath);
			List<string> TargetFiles = new List<string>();
			foreach(var FilePath in AllFile)
			{
				if(Path.GetExtension(FilePath) != ".bin") { continue; }
				TargetFiles.Add(FilePath);
			}
			VersionGenerator VersionGen = new VersionGenerator(TargetFiles.ToArray());
			if(!VersionGen.Generate())
			{
				MessageBox.Show("バージョンファイルの生成に失敗しました。");
				Console.WriteLine("失敗。");
				return false;
			}
			Console.WriteLine("完了。");

			return true;
		}

		/// <summary>
		/// マスタ展開.
		/// </summary>
		/// <param name="Host">ホスト</param>
		/// <param name="UserName">ユーザ名</param>
		/// <param name="Password">パスワード</param>
		/// <returns>成功したらtrueを返す</returns>
		private bool ExpandMaster(string Host, string UserName, string Password)
		{
			ISQLExpand Expander = null;
			if (!Util.IsLocalHost(Host))
			{
				Expander = new RemoteSQLExpander(Host, UserName, Password);
			}
			else
			{
				Expander = new LocalSQLExpander(UserName, Password);
			}

			string[] AllFiles = Directory.GetFiles(Config.TemporaryDirectoryPath);
			List<string> Files = new List<string>();
			foreach(var File in AllFiles)
			{
				if(Path.GetExtension(File) == ".sql")
				{
					Files.Add(File);
				}
			}
			if (!Expander.Expand(Files.ToArray()))
			{
				MessageBox.Show("SQLの展開に失敗しました。");
				return false;
			}
			
			return true;
		}

		/// <summary>
		/// バイナリファイルの転送.
		/// </summary>
		/// <param name="Host">ホスト</param>
		/// <param name="UserName">ユーザ名</param>
		/// <param name="Password">パスワード</param>
		/// <param name="TargetDirectory">転送先ディレクトリ</param>
		/// <returns>成功したらtrueを返す</returns>
		private bool TransportBinaryFiles(string Host, string UserName, string Password, string TargetDirectory)
		{
			string[] AllFiles = Directory.GetFiles(Config.TemporaryDirectoryPath);
			foreach(var FilePath in AllFiles)
			{
				if(Path.GetExtension(FilePath) != ".bin" && Path.GetFileName(FilePath) != "Version.csv") { continue; }

				Console.Write(Path.GetFileName(FilePath) + "の転送中...");
				FileTransporter Transporter = new FileTransporter(FilePath, Host, UserName, Password, TargetDirectory);
				if(!Transporter.Transport())
				{
					MessageBox.Show("バイナリファイルの転送に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");
			}

			return true;
		}

		/// <summary>
		/// 一時ディレクトリの撤去.
		/// </summary>
		private void DeleteTemporaryDirectory()
		{
			string[] Files = Directory.GetFiles(Config.TemporaryDirectoryPath);
			foreach (var FileName in Files)
			{
				File.Delete(FileName);
			}
			Directory.Delete(Config.TemporaryDirectoryPath);
		}

		/// <summary>
		/// 転送対象リストの再読み込み
		/// </summary>
		private void ReloadTransportTargetList()
		{
			TransportTargetList.Items.Clear();
			string[] Files = Directory.GetFiles(Config.TransportTargetsPath);
			foreach(var FileName in Files)
			{
				if(Path.GetExtension(FileName) != ".dat") { continue; }
				TransportTargetList.Items.Add(Path.GetFileNameWithoutExtension(FileName));
			}
		}

		// 転送対象の追加ボタンが押された
		private void AddTransportTargetButton_Click(object sender, EventArgs e)
		{
			AddTransportTargetWindow Window = new AddTransportTargetWindow();
			var Result = Window.ShowDialog();
			if(Result != DialogResult.Cancel)
			{
				ReloadTransportTargetList();
			}
		}
	}
}

