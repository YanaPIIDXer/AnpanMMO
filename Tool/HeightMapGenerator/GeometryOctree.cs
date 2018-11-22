﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// 空間の八分木.
	/// </summary>
	public class GeometryOctree
	{

		/// <summary>
		/// 分割最大数.
		/// </summary>
		private static readonly int MaxLevel = 4;

		private int[] Pow;

		/// <summary>
		/// セルリスト
		/// </summary>
		private GeometryCell[] CellList;

		/// <summary>
		/// 分割されたセルの最大数.
		/// </summary>
		private int CellNum = 0;

		/// <summary>
		/// 分割数.
		/// </summary>
		private int DivisionNum = 8;
		private int ParentShift;

		/// <summary>
		/// 分割レベル
		/// </summary>
		private int Level;

		/// <summary>
		/// 左方向オフセット
		/// </summary>
		private float OffsetLeft;

		/// <summary>
		/// 下方向オフセット
		/// </summary>
		private float OffsetBottom;
		
		/// <summary>
		/// 幅.
		/// </summary>
		private float Width;

		/// <summary>
		/// 高さ
		/// </summary>
		private float Height;
		
		private float UnitWidth;
		private float UnitHeight;
		
		/// <summary>
		/// 初期化.
		/// </summary>
		/// <param name="InLevel">分割レベル</param>
		/// <param name="Left">左の座標</param>
		/// <param name="Right">右の座標</param>
		/// <param name="Top">上の座標</param>
		/// <param name="Bottom">下の座標</param>
		/// <param name="Front">手前の座標</param>
		/// <param name="Back">奥の座標</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Initialize(int InLevel, float Left, float Right, float Top, float Bottom)
		{
			// MaxLevelを超えて初期化しようとしたらエラー
			if(InLevel > MaxLevel + 1) { return false; }

			// MaxLevelに応じた配列を作成.
			Pow = new int[MaxLevel + 2];

			// 各レベルでの空間を算出.
			Pow[0] = 1;
			for(int i = 1; i <= MaxLevel + 1; i++)
			{
				Pow[i] = Pow[i - 1] * DivisionNum;
			}

			// 線形配列作成.
			int Denom = DivisionNum - 1;
			CellNum = (Pow[InLevel + 1] - 1) / Denom;
			CellList = new GeometryCell[CellNum];

			// 有効領域を登録.
			OffsetLeft = Left;
			OffsetBottom = Bottom;
			Width = Right - Left;
			Height = Top - Bottom;
			
			int Unit = 1 << InLevel;
			UnitWidth = Width / Unit;
			UnitHeight = Height / Unit;
			
			Level = InLevel;

			ParentShift = (int)Math.Log(DivisionNum, 2.0f);

			return true;
		}
		
		/// <summary>
		/// 登録.
		/// </summary>
		/// <param name="Left">左</param>
		/// <param name="Top">上</param>
		/// <param name="Right">右</param>
		/// <param name="Bottom">下</param>
		/// <param name="Front">手前</param>
		/// <param name="Back">奥</param>
		/// <param name="Data">登録するデータ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Register(float Left, float Top, float Right, float Bottom, GeometryTreeData Data)
		{
			// 指定領域の分オフセットして計算する。
			if(!OffsetPosition(ref Left, ref Top, ref Right, ref Bottom)) { return false; }

			// オブジェクトの境界領域からモートン番号を算出.
			int BelongLevel;
			int Elem = GetMortonNumber(Left, Top, Right, Bottom, out BelongLevel);
			Elem = ToLinearSpace(Elem, BelongLevel);

			// 算出されたモートン番号が生成した空間分割数より大きい場合はエラー
			if(Elem >= CellNum) { return false; }

			// 算出されたモートン番号の空間が無い場合は新規作成.
			if(CellList[Elem] == null)
			{
				CreateNewCell(Elem);
			}

			return CellList[Elem].Push(Data);
		}

		/// <summary>
		/// 登録されているオブジェクトの衝突リストを取得する。
		/// </summary>
		/// <param name="X">X座標</param>
		/// <param name="Y">Y座標</param>
		/// <param name="CollisionList">衝突リスト</param>
		/// <returns>衝突リストの数</returns>
		public int GetCollisionList(float X, float Y, List<Geometry> CollisionList)
		{
			CollisionList.Clear();

			// ルート空間の存在をチェック
			if(CellList[0] == null) { return 0; }

			// 線分.
			float Top = Y;
			float Left = X;
			float Bottom = Y;
			float Right = X;
			
			// 指定領域の分オフセットする。
			if(!OffsetPosition(ref Left, ref Top, ref Right, ref Bottom)) { return 0; }

			// モートン番号を算出.
			int BelongLevel;
			int Elem = GetMortonNumber(Left, Top, Right, Bottom, out BelongLevel);

			if(!GetCollisionList_Rec(Elem, CollisionList)) { return 0; }

			return CollisionList.Count;
		}

		/// <summary>
		/// コリジョンリストの取得（再帰関数）
		/// </summary>
		/// <param name="Elem">モートン番号</param>
		/// <param name="CollisionList">コリジョンリスト</param>
		/// <returns>成功したらtrueを返す。</returns>
		private bool GetCollisionList_Rec(int Elem, List<Geometry> CollisionList)
		{
			GeometryTreeData Data = CellList[Elem].FirstData;

			while(Data != null)
			{
				CollisionList.Add(Data.Object);
				Data = Data.Next;
			}
			
			// 子空間へ移動.
			int NextElem;

			// 子空間を巡る
			for (int i = 0; i < DivisionNum; i++)
			{
				NextElem = Elem * DivisionNum + 1 + i;

				// 空間分割数以上 or 対象空間が無い場合はスキップ。
				bool bSkip = (NextElem >= CellNum || CellList[NextElem] == null);
				if (bSkip) { continue; }

				// 子空間を検索.
				GetCollisionList_Rec(NextElem, CollisionList);
			}

			return true;
		}
		
		/// <summary>
		/// 指定された番号の空間オブジェクトを新規作成.
		/// </summary>
		/// <param name="Elem">空間番号</param>
		/// <returns>成功したらtrueを返す。</returns>
		private bool CreateNewCell(int Elem)
		{
			while(CellList[Elem] == null)
			{
				CellList[Elem] = new GeometryCell();

				// 存在していなければ親空間を作成する。
				Elem = (Elem - 1) >> ParentShift;

				if(Elem == -1)
				{
					// ルート空間の場合は-1になるため終了。
					break;
				}
				else if (Elem >= CellNum)
				{
					// 空間分割数以上になったら終了。
					break;
				}
			}

			return true;
		}

		/// <summary>
		/// 線形配列のインデックスに変換.
		/// </summary>
		/// <param name="MortonNum">モートン番号</param>
		/// <param name="InLevel">レベル</param>
		/// <returns></returns>
		private int ToLinearSpace(int MortonNum, int InLevel)
		{
			int Denom = DivisionNum - 1;
			int AdditiveNum = (int)(Math.Pow(DivisionNum, InLevel) - 1) / Denom;
			return MortonNum + AdditiveNum;
		}

		/// <summary>
		/// 指定領域の分オフセットして計算.
		/// </summary>
		/// <param name="Left">左</param>
		/// <param name="Top">上</param>
		/// <param name="Right">右</param>
		/// <param name="Bottom">下</param>
		/// <param name="Front">手前</param>
		/// <param name="Back">奥</param>
		/// <returns>成功したらtrueを返す。</returns>
		private bool OffsetPosition(ref float Left, ref float Top, ref float Right, ref float Bottom)
		{
			Left -= OffsetLeft;
			Right -= OffsetLeft;
			Top -= OffsetBottom;
			Bottom -= OffsetBottom;
			
			if (Left < 0) { return false; }
			if (Right > Width) { return false; }
			if (Bottom < 0) { return false; }
			if (Top > Height) { return false; }
			
			return true;
		}

		/// <summary>
		/// モートン番号を算出.
		/// </summary>
		/// <param name="Left">左</param>
		/// <param name="Top">上</param>
		/// <param name="Right">右</param>
		/// <param name="Bottom">下</param>
		/// <param name="Front">手前</param>
		/// <param name="Back">奥</param>
		/// <param name="BelongLevel">所属する空間のレベル</param>
		/// <returns>モートン番号</returns>
		private int GetMortonNumber(float Left, float Top, float Right, float Bottom, out int BelongLevel)
		{
			// 左上手前のモートン番号を算出.
			int LtdX = (int)(Left / UnitWidth);
			int LtdY = (int)(Top / UnitHeight);
			int Ltd = BitSeparate2D(LtdX) | (BitSeparate2D(LtdY) << 1);

			// 右下奥のモートン番号を算出.
			int RbdX = (int)(Right / UnitWidth);
			int RbdY = (int)(Bottom / UnitHeight);
			int Rbd = BitSeparate2D(RbdX) | (BitSeparate2D(RbdY) << 1);

			// 左上と右下のモートン番号のxorを取る。
			int Xor = Ltd ^ Rbd;
			int i = 0;
			int Shift = 0;
			int SpaceIndex = 0;

			while(Xor != 0)
			{
				if((Xor & 0x7) != 0)
				{
					// 空間シフト数を採用.
					SpaceIndex = (i + 1);
					Shift = SpaceIndex * 2;
				}

				// 2bitシフトさせて再チェック。
				Xor >>= 2;
				i++;
			}

			// モートン番号.
			int Morton = Rbd >> Shift;

			// 所属する空間のレベル
			BelongLevel = Level - SpaceIndex;

			return Morton;
		}

		/// <summary>
		/// 渡された引数をbitで飛び飛びにしたものにする（２Ｄ版）
		/// </summary>
		/// <param name="n">変換したい値</param>
		/// <returns>変換後の値</returns>
		private static int BitSeparate2D(int n)
		{
			n = (n | (n << 8)) & 0x00ff00ff;
			n = (n | (n << 4)) & 0x0f0f0f0f;
			n = (n | (n << 2)) & 0x33333333;
			return (n | (n << 1)) & 0x55555555;
		}
		
	}
	
}