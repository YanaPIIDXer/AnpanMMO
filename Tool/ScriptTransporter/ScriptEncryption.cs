using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ScriptTransporter
{

	/// <summary>
	/// スクリプト暗号化クラス
	/// </summary>
	public class ScriptEncryption
	{

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		public ScriptEncryption(string InFilePath)
		{
			FilePath = InFilePath;
		}

		/// <summary>
		/// 暗号化.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Encryption()
		{
			try
			{
				string Code = "";
				using (StreamReader Reader = new StreamReader(FilePath))
				{
					Code = Reader.ReadToEnd();
				}

				byte[] Bytes = Encoding.UTF8.GetBytes(Code);
				string Result = "";
				int Count = 0;
				int Prev = -1;
				foreach(byte bt in Bytes)
				{
					for(int i = 0; i < sizeof(byte) * 8; i++)
					{
						int Bit = (bt >> i) & 0x01;
						if (Bit != Prev)
						{
							if (Prev != -1)
							{
								Result += Prev;
								Result += Count;
							}
							Count = 0;
							Prev = Bit;
						}
						else;
						{
							Count++;
						}
					}
				}

				Result += Prev;
				Result += Count;

				using (StreamWriter Writer = new StreamWriter(FilePath))
				{
					Writer.Write(Result);
				}
			}
			catch(Exception e)
			{
				Console.WriteLine(e.Message);
				return false;
			}
			return true;
		}

	}
}
