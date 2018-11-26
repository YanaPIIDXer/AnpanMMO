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
		/// 左端.
		/// </summary>
		public float Left { get; private set; }

		/// <summary>
		/// 右端.
		/// </summary>
		public float Right { get; private set; }

		/// <summary>
		/// 上.
		/// </summary>
		public float Top { get; private set; }

		/// <summary>
		/// 下.
		/// </summary>
		public float Bottom { get; private set; }

		/// <summary>
		/// 奥.
		/// </summary>
		public float Front { get; private set; }

		/// <summary>
		/// 手前.
		/// </summary>
		public float Back { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public Geometry()
		{
			VertexList = new List<Vector>();
			Left = 0.0f;
			Right = 0.0f;
			Top = 0.0f;
			Bottom = 0.0f;
			Front = 0.0f;
			Back = 0.0f;
		}

		/// <summary>
		/// 頂点追加.
		/// </summary>
		/// <param name="Vertex">頂点データ</param>
		public void AddVertex(Vector Vertex)
		{
			VertexList.Insert(0, Vertex);

			if(Vertex.X > Back)
			{
				Back = Vertex.X;
			}
			if(Vertex.X < Front)
			{
				Front = Vertex.X;
			}
			if(Vertex.Y > Right)
			{
				Right = Vertex.Y;
			}
			if(Vertex.Y < Left)
			{
				Left = Vertex.Y;
			}
			if(Vertex.Z > Top)
			{
				Top = Vertex.Z;
			}
			if(Vertex.Z < Bottom)
			{
				Bottom = Vertex.Z;
			}
		}

		/// <summary>
		/// 範囲内か？
		/// </summary>
		/// <param name="X">X座標</param>
		/// <param name="Y">Y座標</param>
		/// <returns>範囲内であればtrueを返す</returns>
		public bool IsInRange(float X, float Y)
		{
			return (X <= Back && X >= Front && Y <= Right && Y >= Left);
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

			if(!IsInRange(X, Y)) { return false; }
			
			Vector Origin = new Vector(X, Y, Config.HeightMax);
			Vector Ray = new Vector(0.0f, 0.0f, Config.HeightMin);

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
