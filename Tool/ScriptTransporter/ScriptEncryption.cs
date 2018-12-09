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
				int Count = 0;
				int Prev = -1;

				FileStream WriteStream = new FileStream(FilePath, FileMode.Create);
				using (BinaryWriter BinWriter = new BinaryWriter(WriteStream))
				{
					foreach (byte bt in Bytes)
					{
						for (int i = 0; i < sizeof(byte) * 8; i++)
						{
							int Bit = (bt >> i) & 0x01;
							if (Bit != Prev)
							{
								if (Prev != -1)
								{
									byte[] PrevBytes = BitConverter.GetBytes(Prev).Reverse().ToArray();
									byte[] CountBytes = BitConverter.GetBytes(Count).Reverse().ToArray();
									BinWriter.Write(PrevBytes);
									BinWriter.Write(CountBytes);
								}
								Count = 1;
								Prev = Bit;
							}
							else;
							{
								Count++;
							}
						}
					}

					byte[] PrevByte = BitConverter.GetBytes(Prev).Reverse().ToArray();
					byte[] CountByte = BitConverter.GetBytes(Count).Reverse().ToArray();
					BinWriter.Write(PrevByte);
					BinWriter.Write(CountByte);
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
