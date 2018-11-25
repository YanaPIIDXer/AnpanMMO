using System;
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
		/// ジオメトリグループリスト
		/// </summary>
		private List<GeometryGroup> GeometryGroups = new List<GeometryGroup>();

		/// <summary>
		/// 現在のジオメトリグループ
		/// </summary>
		private GeometryGroup CurrentGeometryGroup
		{
			get
			{
				if(GeometryGroups.Count == 0) { return null; }
				int Index = GeometryGroups.Count - 1;
				return GeometryGroups[Index];
			}
		}
		
		/// <summary>
		/// 左端.
		/// </summary>
		private float Left;

		/// <summary>
		/// 右端.
		/// </summary>
		private float Right;

		/// <summary>
		/// 上.
		/// </summary>
		private float Top;

		/// <summary>
		/// 下.
		/// </summary>
		private float Bottom;

		/// <summary>
		/// 正面.
		/// </summary>
		private float Front;

		/// <summary>
		/// 後ろ
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
			Top = 0.0f;
			Bottom = 0.0f;
			Front = 0.0f;
			Back = 0.0f;

			GeometryGroup Group = new GeometryGroup();
			GeometryGroups.Add(Group);
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

						if(X > Back)
						{
							Back = X;
						}
						if(X < Front)
						{
							Front = X;
						}
						if (Y < Left)
						{
							Left = Y;
						}
						if (Y > Right)
						{
							Right = Y;
						}
						if(Z > Top)
						{
							Top = Z;
						}
						if(Z < Bottom)
						{
							Bottom = Z;
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
						CurrentGeometryGroup.AddGeometry(Geo);
						if(CurrentGeometryGroup.IsMax)
						{
							GeometryGroup NewGroup = new GeometryGroup();
							GeometryGroups.Add(NewGroup);
						}
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

			bool bHit = false;
			float MaxHeight = float.MinValue;
			foreach(var Group in GeometryGroups)
			{
				if(Group.TryGetHeight(X, Y, out Height))
				{
					if(Height > MaxHeight)
					{
						bHit = true;
						MaxHeight = Height;
					}
				}
			}
			
			return (bHit ? MaxHeight : Config.HeightMin);
		}

	}
}
