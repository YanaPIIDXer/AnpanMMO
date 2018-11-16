using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// バイナリ生成クラス
	/// </summary>
	public class BinaryGenerator
	{

		/// <summary>
		/// マスタ名.
		/// </summary>
		private string MasterName;

		/// <summary>
		/// カラムリスト
		/// </summary>
		private List<Column> Columns;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InMasterName">マスタ名</param>
		/// <param name="InColumns">カラムリスト</param>
		public BinaryGenerator(string InMasterName, List<Column> InColumns)
		{
			MasterName = InMasterName;
			Columns = InColumns;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			try
			{
				string FilePath = Config.TemporaryDirectoryPath + "\\" + MasterName + ".bin";
				FileStream WriteStream = new FileStream(FilePath, FileMode.Create);
				using (BinaryWriter BinWriter = new BinaryWriter(WriteStream))
				{
					for (int i = 0; ; i++)
					{
						if (i >= Columns[0].DataList.Count) { break; }
						for (int j = 0; j < Columns.Count; j++)
						{
							byte[] Bytes = null;
							double Data = 0.0;
							if (Columns[j].DataType != Type.String)
							{
								Data = (double)Columns[j].DataList[i];
							}
							switch (Columns[j].DataType)
							{
								case Type.s8:

									Bytes = BitConverter.GetBytes((char)Data);
									break;

								case Type.u8:

									Bytes = BitConverter.GetBytes((byte)Data);
									break;

								case Type.s16:

									Bytes = BitConverter.GetBytes((short)Data);
									break;

								case Type.u16:

									Bytes = BitConverter.GetBytes((ushort)Data);
									break;

								case Type.s32:

									Bytes = BitConverter.GetBytes((int)Data);
									break;

								case Type.u32:

									Bytes = BitConverter.GetBytes((uint)Data);
									break;

								case Type.Float:

									Bytes = BitConverter.GetBytes((float)Data);
									break;

								case Type.String:

									string Str = (string)Columns[j].DataList[i];
									byte[] SizeBytes = BitConverter.GetBytes(Str.Length);
									if (BitConverter.IsLittleEndian)
									{
										SizeBytes = SizeBytes.Reverse().ToArray();
									}
									BinWriter.Write(SizeBytes);
									Bytes = Encoding.GetEncoding("shift-jis").GetBytes(Str).Reverse().ToArray();
									break;
							}
							if (BitConverter.IsLittleEndian)
							{
								Bytes = Bytes.Reverse().ToArray();
							}

							BinWriter.Write(Bytes);
						}
					}
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
