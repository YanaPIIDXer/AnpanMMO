using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace HeightMapGenerator
{

	/// <summary>
	/// .objファイル読み込みクラス
	/// </summary>
	public class ObjFileReader
	{

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		public ObjFileReader(string InFilePath)
		{
			FilePath = InFilePath;
		}

		/// <summary>
		/// 読み込み
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Load()
		{
			try
			{
				using (StreamReader Reader = new StreamReader(FilePath))
				{
					while(!Reader.EndOfStream)
					{
						string Line = Reader.ReadLine();
						ParseLine(Line);
					}
				}
			}
			catch
			{
				return false;
			}
			return true;
		}

		/// <summary>
		/// 行の解析.
		/// </summary>
		/// <param name="Line">行</param>
		private void ParseLine(string Line)
		{
			string KeyWord = Line.Split(' ')[0];

		}

	}
}
