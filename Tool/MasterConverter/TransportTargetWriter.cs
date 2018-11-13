using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// 転送対象書き込みクラス
	/// </summary>
	public class TransportTargetWriter
	{

		/// <summary>
		/// ファイル名.
		/// </summary>
		private string FileName;

		/// <summary>
		/// ユーザ名.
		/// </summary>
		private string UserName;

		/// <summary>
		/// パスワード
		/// </summary>
		private string Password;

		/// <summary>
		/// バイナリ転送先パス
		/// </summary>
		private string BinaryPath;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFileName">ファイル名</param>
		/// <param name="InUserName">ユーザ名</param>
		/// <param name="InPassword">パスワード</param>
		/// <param name="InBinaryPath">バイナリ転送先パス</param>
		public TransportTargetWriter(string InFileName, string InUserName, string InPassword, string InBinaryPath)
		{
			FileName = InFileName + ".dat";
			UserName = InUserName;
			Password = InPassword;
			BinaryPath = InBinaryPath;
		}

		/// <summary>
		/// 書き込み
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Write()
		{
			try
			{
				using (StreamWriter Writer = new StreamWriter(Config.TransportTargetsPath + "\\" + FileName))
				{
					Writer.WriteLine(UserName);
					Writer.WriteLine(Password);
					Writer.WriteLine(BinaryPath);
				}
			}
			catch
			{
				return false;
			}

			return true;
		}

	}
}
