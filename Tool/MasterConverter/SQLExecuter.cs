using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Renci.SshNet;

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

					// .sqlファイルを列挙.
					ExecuteCommand(Client, "ls -1 " + Config.HostSQLPath, false, out Result);
					string[] SQLFiles = Result.Split('\n');

					// 片っ端からデータベースにブチ込む。
					foreach(var SQLFile in SQLFiles)
					{
						if (String.IsNullOrEmpty(SQLFile)) { continue; }
						var FilePath = Config.HostSQLPath + "/" + SQLFile;
						if(!ExecuteCommand(Client, "mysql -u " + UserName + " -p" + Password + " -D AnpanMMO < " + FilePath, true, out Result))
						{
							return false;
						}
					}

					// 後片付け
					ExecuteCommand(Client, "rm -rf " + Config.HostSQLPath, false, out Result);
					
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
		/// <param name="OutputToConsole">コンソールにコマンドを出力するか？</param>
		/// <param name="Result">結果</param>
		/// <returns>成功したらtrueを返す</returns>
		private bool ExecuteCommand(SshClient Client, string Command, bool OutputToConsole, out string Result)
		{
			bool bCommandSuccess = false;
			try
			{
				using (SshCommand Cmd = Client.CreateCommand(Command))
				{
					Cmd.Execute();
					if(OutputToConsole)
					{
						Console.WriteLine(Cmd.CommandText);
					}
					Result = Cmd.Result;
					bCommandSuccess = (Cmd.ExitStatus == 0);
				}
			}
			catch(Exception e)
			{
				Console.WriteLine("");
				Console.WriteLine(e.Message);
				Result = "";
				return false;
			}

			return bCommandSuccess;
		}

	}
}
