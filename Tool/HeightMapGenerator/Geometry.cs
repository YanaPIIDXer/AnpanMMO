using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// 多角形データ
	/// </summary>
	public class Geometry
	{

		/// <summary>
		/// 頂点リスト
		/// </summary>
		public List<Vector> VertexList { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public Geometry()
		{
			VertexList = new List<Vector>();
		}

		/// <summary>
		/// 頂点追加.
		/// </summary>
		/// <param name="Vertex">頂点データ</param>
		public void AddVertex(Vector Vertex)
		{
			VertexList.Add(Vertex);
		}

	}
}
