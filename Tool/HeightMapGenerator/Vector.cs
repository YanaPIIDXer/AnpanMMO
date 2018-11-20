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

	}
}
