using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// ベクトルクラス
	/// </summary>
	public class Vector
	{

		/// <summary>
		/// X
		/// </summary>
		public float X;

		/// <summary>
		/// Y
		/// </summary>
		public float Y;

		/// <summary>
		/// Z
		/// </summary>
		public float Z;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public Vector()
		{
			X = 0.0f;
			Y = 0.0f;
			Z = 0.0f;
		}

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InX">X</param>
		/// <param name="InY">Y</param>
		/// <param name="InZ">Z</param>
		public Vector(float InX, float InY, float InZ)
		{
			X = InX;
			Y = InY;
			Z = InZ;
		}

		/// <summary>
		/// 内積.
		/// </summary>
		/// <param name="A">ベクトルＡ</param>
		/// <param name="B">ベクトルＢ</param>
		/// <returns>内積の値</returns>
		public static float Dot(Vector A, Vector B)
		{
			return (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
		}

		/// <summary>
		/// 外積.
		/// </summary>
		/// <param name="A">ベクトルＡ</param>
		/// <param name="B">ベクトルＢ</param>
		/// <returns>外積を取った結果</returns>
		public static Vector Cross(Vector A, Vector B)
		{
			Vector Vec = new Vector();
			Vec.X = (A.Y * B.Z) - (A.Z * B.Y);
			Vec.Y = (A.Z * B.X) - (A.X * B.Z);
			Vec.Z = (A.X * B.Y) - (A.Y * B.X);
			return Vec;
		}


		#region オペレータオーバーロード

		public static Vector operator +(Vector A, Vector B)
		{
			return new Vector(A.X + B.X, A.Y + B.Y, A.Z + B.Z);
		}

		public static Vector operator -(Vector A, Vector B)
		{
			return new Vector(A.X - B.X, A.Y - B.Y, A.Z - B.Z);
		}

		#endregion


	}
}
