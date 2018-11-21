using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// コンフィグ
	/// </summary>
	public class Config
	{

		/// <summary>
		/// 高さの下限値.
		/// </summary>
		public static readonly float HeightMin = -10000.0f;

		/// <summary>
		/// 高さの上限値.
		/// </summary>
		public static readonly float HeightMax = 10000.0f;

		/// <summary>
		/// .objファイルを格納するディレクトリ
		/// </summary>
		public static readonly string ObjFilesDirectory = "Objs";

		/// <summary>
		/// ビットマップを格納するディレクトリ
		/// </summary>
		public static readonly string BitMapDirectory = "HeightMaps";

	}
}
