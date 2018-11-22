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
		/// 幅下限値.
		/// </summary>
		public static readonly float WidthMin = -10000.0f;

		/// <summary>
		/// 幅上限値.
		/// </summary>
		public static readonly float WidthMax = 10000.0f;

		/// <summary>
		/// 奥行き下限値.
		/// </summary>
		public static readonly float DepthMin = -10000.0f;

		/// <summary>
		/// 奥行き上限値.
		/// </summary>
		public static readonly float DepthMax = 10000.0f;

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
