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
	public partial class Form1 : Form
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
		/// サーバソースディレクトリ
		/// </summary>
		private string ServerSourceDirectory = "";

		/// <summary>
		/// クライアントソースディレクトリ
		/// </summary>
		private string ClientSourceDirectory = "";
		
		public Form1()
		{
			InitializeComponent();
			LoadSourceDirectorySetting();
		}

		// 出力ボタンが押された
		private void OutputButton_Click(object sender, EventArgs e)
		{
			// .sql生成.
			if (!GenerateSQLFiles())
			{
				DeleteTemporaryDirectory();
				return;
			}

			// テスト用
			string Host = "";
			string UserName = "";
			string Password = "";
			using (StreamReader Stream = new StreamReader("FTPData.txt"))
			{
				Host = Stream.ReadLine();
				UserName = Stream.ReadLine();
				Password = Stream.ReadLine();
			}

			// マスタ展開.
			if(!ExpandMaster(Host, UserName, Password))
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
				}
			}

			using (StreamReader Reader = new StreamReader(SourceDirectorySettingFileName))
			{
				ServerSourceDirectory = Reader.ReadLine();
				ClientSourceDirectory = Reader.ReadLine();
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
				if(Path.GetExtension(TargetFilePath) != ".xlsx") { continue; }
				Console.Write(TargetFilePath + "の展開中...");
				ExcelParser Parser = new ExcelParser(TargetFilePath);
				if (!Parser.Load())
				{
					MessageBox.Show("Excelファイルの解析に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");

				string MasterName = Path.GetFileNameWithoutExtension(TargetFilePath);
				string FileName = MasterName + ".sql";
				string FilePath = Config.TemporaryDirectoryPath + "\\" + FileName;
				Console.Write(FilePath + "の生成中...");

				SQLGenerator SQLGen = new SQLGenerator(FilePath, Parser.Columns);
				if (!SQLGen.Generate())
				{
					MessageBox.Show("SQLファイルの生成に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
				Console.WriteLine("完了。");

				Console.Write("サーバソースの生成中...");

				ServerSorceGenerator ServerSource = new ServerSorceGenerator(ServerSourceDirectory, MasterName, Parser.Columns);
				if(!ServerSource.Generate())
				{
					MessageBox.Show("サーバソースの生成に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}

				Console.WriteLine("完了。");
			}
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

			string[] Files = Directory.GetFiles(Config.TemporaryDirectoryPath);
			if (!Expander.Expand(Files))
			{
				MessageBox.Show("SQLの展開に失敗しました。");
				return false;
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

	}
}
