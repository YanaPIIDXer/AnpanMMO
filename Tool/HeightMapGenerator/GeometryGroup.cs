using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// ジオメトリグループ
	/// </summary>
	public class GeometryGroup
	{

		/// <summary>
		/// ジオメトリ最大数.
		/// </summary>
		private static readonly int MaxCount = 5000;

		/// <summary>
		/// ジオメトリリスト
		/// </summary>
		private List<Geometry> GeometryList = new List<Geometry>();

		/// <summary>
		/// 左.
		/// </summary>
		public float Left { get; private set; }

		/// <summary>
		/// 右.
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
		/// 最大か？
		/// </summary>
		public bool IsMax
		{
			get
			{
				return (GeometryList.Count >= MaxCount);
			}
		}

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public GeometryGroup()
		{
			Left = 0.0f;
			Right = 0.0f;
			Top = 0.0f;
			Bottom = 0.0f;
			Front = 0.0f;
			Back = 0.0f;
		}

		/// <summary>
		/// ジオメトリ追加.
		/// </summary>
		/// <param name="TargetGeometry">ジオメトリ</param>
		public void AddGeometry(Geometry TargetGeometry)
		{
			if(IsMax)
			{
				throw new Exception("ジオメトリの数が最大です。");
			}

			GeometryList.Add(TargetGeometry);

			if (TargetGeometry.Back > Back)
			{
				Back = TargetGeometry.Back;
			}
			if (TargetGeometry.Front < Front)
			{
				Front = TargetGeometry.Front;
			}
			if (TargetGeometry.Right > Right)
			{
				Right = TargetGeometry.Right;
			}
			if (TargetGeometry.Left < Left)
			{
				Left = TargetGeometry.Left;
			}
			if (TargetGeometry.Top > Top)
			{
				Top = TargetGeometry.Top;
			}
			if (TargetGeometry.Bottom < Bottom)
			{
				Bottom = TargetGeometry.Bottom;
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
		/// 高さを取得する.
		/// </summary>
		/// <param name="X">X座標</param>
		/// <param name="Y">Y座標</param>
		/// <param name="Height">高さ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool TryGetHeight(float X, float Y, out float Height)
		{
			Height = 0.0f;

			if (!IsInRange(X, Y)) { return false; }

			bool bHit = false;
			float MaxHeight = float.MinValue;
			foreach(var Geo in GeometryList)
			{
				if(Geo.TryGetHeight(X, Y, out Height))
				{
					bHit = true;
					if(Height > MaxHeight)
					{
						MaxHeight = Height;
					}
				}
			}

			Height = MaxHeight;
			return bHit;
		}

	}
}
