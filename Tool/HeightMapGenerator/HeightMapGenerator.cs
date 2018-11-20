using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// ハイトマップ生成クラス
	/// </summary>
	public class HeightMapGenerator
	{

		/// <summary>
		/// .objのファイルパス
		/// </summary>
		private string ObjFilePath;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InObjFilePath">.objのファイルパス</param>
		public HeightMapGenerator(string InObjFilePath)
		{
			ObjFilePath = InObjFilePath;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Generate()
		{
			return true;
		}

	}
}
