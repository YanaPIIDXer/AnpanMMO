using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// 木構造に登録されるデータ
	/// </summary>
	public class GeometryTreeData
	{

		/// <summary>
		/// セルデータ
		/// </summary>
		private GeometryCell _Cell;
		public GeometryCell Cell
		{
			get
			{
				return _Cell;
			}

			set
			{
				if(value == _Cell) { return; }
				if(value == null) { return; }
				_Cell = value;
			}
		}

		/// <summary>
		/// ジオメトリグループ
		/// </summary>
		public GeometryGroup Object { get; private set; }
		
		/// <summary>
		/// 前のデータ
		/// </summary>
		public GeometryTreeData Prev { get; set; }

		/// <summary>
		/// 次のデータ
		/// </summary>
		public GeometryTreeData Next { get; set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InObject">ジオメトリグループ</param>
		public GeometryTreeData(GeometryGroup InObject)
		{
			Object = InObject;
		}

	}
}
