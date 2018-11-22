using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// 空間セル
	/// </summary>
	public class GeometryCell
	{

		/// <summary>
		/// 最後に登録されたデータ
		/// </summary>
		private GeometryTreeData LatestData;
		public GeometryTreeData FirstData
		{
			get { return LatestData; }
		}

		/// <summary>
		/// 空間にTreeDataを登録する。
		/// </summary>
		/// <param name="Data">登録するTreeData</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Push(GeometryTreeData Data)
		{
			// 二重登録.
			if(Data.Cell == this) { return false; }

			Data.Cell = this;

			// まだ空間に一つも登録が無い場合は始めのデータとして登録。
			if(LatestData == null)
			{
				LatestData = Data;
				return true;
			}

			// 最新のTreeDataの参照を更新.
			Data.Next = LatestData;
			LatestData.Prev = Data;
			LatestData = Data;

			return true;
		}

	}
}
