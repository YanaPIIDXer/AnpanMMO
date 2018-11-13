using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// 転送先読み込みクラス
	/// </summary>
	public class TransportTargetReader
	{

		/// <summary>
		/// ファイルパス.
		/// </summary>
		private string FilePath;

		/// <summary>
		/// ホスト
		/// </summary>
		public string Host { get; private set; }

		/// <summary>
		/// ユーザ名.
		/// </summary>
		public string UserName { get; private set; }

		/// <summary>
		/// パスワード
		/// </summary>
		public string Password { get; private set; }

		/// <summary>
		/// バイナリパス
		/// </summary>
		public string BinaryPath { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="FileName">ファイル名</param>
		public TransportTargetReader(string FileName)
		{
			FilePath = Config.TransportTargetsPath + "\\" + FileName + ".dat";
		}

		/// <summary>
		/// 読み込み
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Read()
		{
			try
			{
				using (StreamReader Reader = new StreamReader(FilePath))
				{
					Host = Reader.ReadLine();
					UserName = Reader.ReadLine();
					Password = Reader.ReadLine();
					BinaryPath = Reader.ReadLine();
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
