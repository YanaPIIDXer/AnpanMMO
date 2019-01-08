using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Renci.SshNet;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// SQL実行クラス
	/// </summary>
	public class SQLExecuter
	{

		/// <summary>
		/// ホスト
		/// </summary>
		private string Host;

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
		/// <param name="InHost">ホスト</param>
		/// <param name="InUserName">ユーザ名</param>
		/// <param name="InPassword">パスワード</param>
		public SQLExecuter(string InHost, string InUserName, string InPassword)
		{
			Host = InHost;
			UserName = InUserName;
			Password = InPassword;
		}

		/// <summary>
		/// 実行.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Execute()
		{
			try
			{
				var AuthMethod = new PasswordAuthenticationMethod(UserName, Password);
				var ConnInfo = new ConnectionInfo(Host, UserName, AuthMethod);
				using (var Client = new SshClient(ConnInfo))
				{
					Client.Connect();

					Console.WriteLine("");
					string Result = "";
					string Error = "";

					// 一旦マスタを全消去.
					string AllRemoveCommand = GenerateMySQLCommand("-e 'show tables from " + Config.MasterDataBaseName + "'");
					AllRemoveCommand += " | grep ~*";
					AllRemoveCommand += " | grep -v Tables_in";
					AllRemoveCommand += " | xargs -I \"@@\" " + GenerateMySQLCommand("-e 'drop table " + Config.MasterDataBaseName + ".@@'");
					ExecuteCommand(Client, AllRemoveCommand, out Result, out Error);
					
					// .sqlファイルを列挙.
					ExecuteCommand(Client, "ls -1 " + Config.HostSQLPath, out Result, out Error);
					string[] SQLFiles = Result.Split('\n');

					// 片っ端からデータベースにブチ込む。
					foreach(var SQLFile in SQLFiles)
					{
						if (String.IsNullOrEmpty(SQLFile)) { continue; }
						var FilePath = Config.HostSQLPath + "/" + SQLFile;
						Console.Write(Path.GetFileNameWithoutExtension(FilePath) + "の展開中...");
						if(!ExecuteCommand(Client, GenerateMySQLCommand("-D " + Config.MasterDataBaseName + " < " + FilePath), out Result, out Error))
						{
							Console.WriteLine("失敗。");
							Console.WriteLine(Error);
							return false;
						}

						Console.WriteLine("完了。");
					}

					// 後片付け
					ExecuteCommand(Client, "rm -rf " + Config.HostSQLPath, out Result, out Error);
					
					Client.Disconnect();
				}
			}
			catch(Exception e)
			{
				Console.WriteLine("");
				Console.WriteLine(e.Message);
				return false;
			}

			return true;
		}

		/// <summary>
		/// コマンド実行.
		/// </summary>
		/// <param name="Client">SSHクライアント</param>
		/// <param name="Command">コマンド</param>
		/// <param name="Result">結果</param>
		/// <returns>成功したらtrueを返す</returns>
		private bool ExecuteCommand(SshClient Client, string Command, out string Result, out string Error)
		{
			Result = "";
			Error = "";
			bool bCommandSuccess = false;
			try
			{
				using (SshCommand Cmd = Client.CreateCommand(Command))
				{
					Cmd.Execute();
					Result = Cmd.Result;
					bCommandSuccess = (Cmd.ExitStatus == 0);
					if(!bCommandSuccess)
					{
						Error = Cmd.Error;
					}
				}
			}
			catch(Exception e)
			{
				Console.WriteLine("");
				Console.WriteLine(e.Message);
				return false;
			}

			return bCommandSuccess;
		}

		/// <summary>
		/// MySQLのコマンドを生成.
		/// </summary>
		/// <param name="Arg">引数</param>
		/// <returns>MySQLのコマンド</returns>
		private string GenerateMySQLCommand(string Arg)
		{
			return "mysql -u " + UserName + " -p" + Password + " " + Arg;
		}

	}
}
