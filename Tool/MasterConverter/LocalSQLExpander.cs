using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace MasterConverter
{

	/// <summary>
	/// ローカル向けSQL展開クラス
	/// </summary>
	class LocalSQLExpander : ISQLExpand
	{

		/// <summary>
		/// ユーザ名.
		/// </summary>
		private string UserName;

		/// <summary>
		/// パスワード
		/// </summary>
		private string Password;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InUserName">ユーザ名</param>
		/// <param name="InPassword">パスワード</param>
		public LocalSQLExpander(string InUserName, string InPassword)
		{
			UserName = InUserName;
			Password = InPassword;
		}

		/// <summary>
		/// 展開.
		/// </summary>
		/// <param name="FileList">ファイルリスト</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Expand(string[] FileList)
		{
			Console.WriteLine("SQLファイルの展開中...");

			foreach(var FilePath in FileList)
			{
				if(!ExpandFile(FilePath))
				{
					MessageBox.Show("SQLファイルの展開に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
			}
			return true;
		}

		/// <summary>
		/// ファイルの展開.
		/// </summary>
		/// <param name="FilePath">ファイルパス</param>
		/// <returns>成功したらtrueを返す。</returns>
		private bool ExpandFile(string FilePath)
		{
			// 一旦消去.
			string RemoveArg = "/c for /f %i in ('" + GenerateMySQLCommand("-e \"show tables from " + Config.MasterDataBaseName + "\"");
			RemoveArg += " ^| findstr ~*";
			RemoveArg += " ^| findstr -v Tables_in')";
			RemoveArg += " do " + GenerateMySQLCommand("-e \"drop table " + Config.MasterDataBaseName + ".%i\"");
			Process RemoveProcess = CreateCmdProcess();
			RemoveProcess.StartInfo.Arguments = RemoveArg;
			RemoveProcess.Start();
			RemoveProcess.WaitForExit();
			RemoveProcess.Close();
			
			// マスタをブチ込む。
			Process AppendProcess = CreateMySQLProcess("-D " + Config.MasterDataBaseName + " < " + FilePath);
			
			string DisplayCommand = "mysql -u " + UserName + " -p" + Password + " -D " + Config.MasterDataBaseName + " < " + FilePath;
			Console.WriteLine(DisplayCommand);

			AppendProcess.Start();

			string Error = AppendProcess.StandardError.ReadToEnd();
			if (Error != "")
			{
				Console.WriteLine(Error);
			}

			AppendProcess.WaitForExit();
			AppendProcess.Close();
			return (Error == "");
		}

		/// <summary>
		/// MySQLのProcessを作成。
		/// </summary>
		/// <param name="Arg"></param>
		/// <returns></returns>
		private Process CreateMySQLProcess(string Arg)
		{
			Process ExpandProcess = CreateCmdProcess();

			string CommandArg = GenerateMySQLCommand(Arg);
			ExpandProcess.StartInfo.Arguments = "/c " + CommandArg;
			return ExpandProcess;
		}

		/// <summary>
		/// コマンドプロンプトのProcessを生成.
		/// </summary>
		/// <returns>Process</returns>
		private Process CreateCmdProcess()
		{
			Process CmdProcess = new Process();

			CmdProcess.StartInfo.FileName = System.Environment.GetEnvironmentVariable("ComSpec");

			CmdProcess.StartInfo.UseShellExecute = false;
			CmdProcess.StartInfo.RedirectStandardError = true;
			CmdProcess.StartInfo.RedirectStandardInput = true;
			CmdProcess.StartInfo.RedirectStandardOutput = true;
			CmdProcess.StartInfo.CreateNoWindow = true;

			return CmdProcess;
		}

		/// <summary>
		/// MySQLのコマンドを生成.
		/// </summary>
		/// <param name="Arg">引数</param>
		/// <returns>コマンド文字列</returns>
		private string GenerateMySQLCommand(string Arg)
		{
			return "mysql -u " + UserName + " -p" + Password + " " + Arg;
		}

	}
}
