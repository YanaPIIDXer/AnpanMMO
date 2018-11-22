﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace HeightMapGenerator
{

	/// <summary>
	/// .objファイル読み込みクラス
	/// </summary>
	public class ObjFile
	{

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// 頂点ディクショナリ
		/// </summary>
		private Dictionary<int, Vector> VertexDic = new Dictionary<int, Vector>();

		/// <summary>
		/// 多角形リスト
		/// </summary>
		private List<Geometry> Geometrys = new List<Geometry>();

		/// <summary>
		/// 八分木.
		/// </summary>
		private GeometryOctree Octree = new GeometryOctree();

		/// <summary>
		/// 左端.
		/// </summary>
		private float Left;

		/// <summary>
		/// 右端.
		/// </summary>
		private float Right;

		/// <summary>
		/// 手前.
		/// </summary>
		private float Front;

		/// <summary>
		/// 奥.
		/// </summary>
		private float Back;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		public ObjFile(string InFilePath)
		{
			FilePath = InFilePath;
			Left = 0.0f;
			Right = 0.0f;
			Front = 0.0f;
			Back = 0.0f;
		}

		/// <summary>
		/// 読み込み
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Load()
		{
			try
			{
				using (StreamReader Reader = new StreamReader(FilePath))
				{
					while(!Reader.EndOfStream)
					{
						string Line = Reader.ReadLine();
						ParseLine(Line);
					}
				}

				// 八分木にデータを登録していく。
				if(!Octree.Initialize(4, Left, Right, Config.DepthMax, Config.DepthMin, Front, Back)) { return false; }
				foreach(var Geo in Geometrys)
				{
					GeometryTreeData Data = new GeometryTreeData(Geo);
					if(!Octree.Register(Geo.Left, Geo.Top, Geo.Right, Geo.Bottom, Geo.Front, Geo.Back, Data)) { return false; }
				}
			}
			catch(Exception e)
			{
				MessageBox.Show(e.Message + "(" + e.StackTrace + ")");
				return false;
			}
			return true;
		}

		/// <summary>
		/// 行の解析.
		/// </summary>
		/// <param name="Line">行</param>
		private void ParseLine(string Line)
		{
			string[] Datas = Line.Split(' ');
			string KeyWord = Datas[0];
			switch(KeyWord)
			{
				case "v":

					{
						float X = float.Parse(Datas[1]);
						float Y = float.Parse(Datas[3]);
						float Z = float.Parse(Datas[2]);
						Vector Vertex = new Vector(X, Y, Z);
						VertexDic.Add(VertexDic.Count + 1, Vertex);

						if(X > Front)
						{
							Front = X;
						}
						if (X < Back)
						{
							Back = X;
						}
						if (Y < Left)
						{
							Left = Y;
						}
						if(Y > Right)
						{
							Right = Y;
						}
					}
					break;

				case "f":

					{
						Geometry Geo = new Geometry();
						for (int i = 1; i < Datas.Length; i++)
						{
							if(Datas[i] == "") { continue; }
							string[] GeometryInfo = Datas[i].Split('/');
							Vector Vertex = VertexDic[int.Parse(GeometryInfo[0])];
							Geo.AddVertex(Vertex);
						}
						Geometrys.Add(Geo);
					}
					break;
			}
		}

		/// <summary>
		/// 高さを取得.
		/// </summary>
		/// <param name="X">X座標</param>
		/// <param name="Y">Y座標</param>
		/// <returns>高さ</returns>
		public float GetHeight(float X, float Y)
		{
			float Height = 0.0f;

			List<Geometry> CollisionList = new List<Geometry>();
			Octree.GetCollisionList(X, Y, CollisionList);
			
			foreach(var Geo in CollisionList)
			{
				if(Geo.TryGetHeight(X, Y, out Height)) { return Height; }
			}
			
			return Config.HeightMin;
		}

	}
}
