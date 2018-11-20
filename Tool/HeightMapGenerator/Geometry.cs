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

		/// <summary>
		/// 高さを取得.
		/// </summary>
		/// <param name="X">X座標</param>
		/// <param name="Y">Y座標</param>
		/// <param name="OutHeight">高さ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool TryGetHeight(float X, float Y, out float OutHeight)
		{
			OutHeight = 0.0f;

			Vector Origin = new Vector(X, Y, 10000.0f);
			Vector Ray = new Vector(0.0f, 0.0f, -10000.0f);

			Vector InvRay = Ray * -1.0f;
			Vector Edge1 = VertexList[1] - VertexList[0];
			Vector Edge2 = VertexList[2] - VertexList[0];

			float Denominator = Vector.Determinant(Edge1, Edge2, InvRay);
			if(Denominator <= 0.0f) { return false; }

			Vector D = Origin - VertexList[0];

			float U = Vector.Determinant(D, Edge2, InvRay) / Denominator;
			if((U < 0.0f) || (U > 1.0f)) { return false; }

			float V = Vector.Determinant(Edge1, D, InvRay) / Denominator;
			if ((V < 0.0f) || (U + V > 1.0f)) { return false; }

			float T = Vector.Determinant(Edge1, Edge2, D) / Denominator;
			if(T < 0.0f) { return false; }

			Vector Tmp = Ray * T;
			OutHeight = Origin.Z + Tmp.Z;
			
			return true;
		}

	}
}
