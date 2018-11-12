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
			Process ExpandProcess = new Process();

			ExpandProcess.StartInfo.FileName = System.Environment.GetEnvironmentVariable("ComSpec");
			
			ExpandProcess.StartInfo.UseShellExecute = false;
			ExpandProcess.StartInfo.RedirectStandardError = true;
			ExpandProcess.StartInfo.RedirectStandardInput = true;
			ExpandProcess.StartInfo.RedirectStandardOutput = true;
			ExpandProcess.StartInfo.CreateNoWindow = true;
			
			string CommandArg = "mysql -u " + UserName + " -p" + Password + " -D AnpanMMO < " + FilePath;
			ExpandProcess.StartInfo.Arguments = "/c " + CommandArg;

			Console.WriteLine(CommandArg);
			
			ExpandProcess.Start();
			
			string Error = ExpandProcess.StandardError.ReadToEnd();
			if(Error != "")
			{
				Console.WriteLine(Error);
			}

			ExpandProcess.WaitForExit();
			ExpandProcess.Close();
			return (Error == "");
		}

	}
}
