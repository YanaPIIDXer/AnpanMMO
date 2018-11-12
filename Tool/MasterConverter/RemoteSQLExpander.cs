using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MasterConverter
{

	/// <summary>
	/// リモート用SQL展開クラス
	/// </summary>
	class RemoteSQLExpander : ISQLExpand
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
		public RemoteSQLExpander(string InHost, string InUserName, string InPassword)
		{
			Host = InHost;
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
			if(!Transport(FileList)) { return false; }
			if (!Execute()) { return false; }

			return true;
		}

		/// <summary>
		/// 転送.
		/// </summary>
		/// <param name="FileList">ファイルリスト</param>
		/// <returns>成功したらtrueを返す。</returns>
		private bool Transport(string[] FileList)
		{
			foreach (var FilePath in FileList)
			{
				Console.WriteLine(FilePath + "の転送中...");

				FileTransporter Transporter = new FileTransporter(FilePath, Host, UserName, Password, Config.HostSQLPath);
				if (!Transporter.Transport())
				{
					MessageBox.Show("SQLファイルの転送に失敗しました。");
					Console.WriteLine("失敗。");
					return false;
				}
			}

			Console.WriteLine("完了。");
			return true;
		}

		/// <summary>
		/// 実行.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		private bool Execute()
		{

			Console.Write("SQLの展開中...");

			SQLExecuter Executer = new SQLExecuter(Host, UserName, Password);
			if (!Executer.Execute())
			{
				MessageBox.Show("SQLの展開に失敗しました。");
				Console.WriteLine("失敗。");
				return false;
			}

			Console.WriteLine("完了。");

			return true;
		}
	}
}
