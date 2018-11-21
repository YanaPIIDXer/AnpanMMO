using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Imaging;
using System.Threading;
using System.IO;

namespace HeightMapGenerator
{

	/// <summary>
	/// ハイトマップ生成クラス
	/// </summary>
	public class HeightMapGenerator
	{

		/// <summary>
		/// ビットマップの幅.
		/// </summary>
		private static readonly int BitmapWidth = 1000;

		/// <summary>
		/// ビットマップの高さ
		/// </summary>
		private static readonly int BitmapHeight = 1000;

		/// <summary>
		/// タスク数.
		/// </summary>
		private static readonly int TaskNum = 8;

		/// <summary>
		/// .objファイルのパス
		/// </summary>
		private string ObjFilePath;

		/// <summary>
		/// objファイル読み込み
		/// </summary>
		private ObjFile ObjData;
		
		/// <summary>
		/// タスクリスト
		/// </summary>
		private List<Task> TaskList = new List<Task>();

		/// <summary>
		/// コンストラクタ
		/// </summary>ask
		/// <param name="InObjFilePath">.objのファイルパス</param>
		public HeightMapGenerator(string InObjFilePath)
		{
			ObjFilePath = InObjFilePath;
			ObjData = new ObjFile(ObjFilePath);
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Generate()
		{
			if(!ObjData.Load())
			{
				MessageBox.Show("objファイルの読み込みに失敗しました。");
				return false;
			}
			
			Bitmap Bmp = new Bitmap(BitmapWidth, BitmapHeight);

			int BmpSize = BitmapWidth * BitmapHeight;

			// クソ重い処理なのでTaskで分散。
			for(int i = 0; i < TaskNum; i++)
			{
				int WriteStart = (int)((i / (float)TaskNum) * BmpSize);
				int WriteEnd = (int)(((i + 1) / (float)TaskNum) * BmpSize);
				Task WriteTask = new Task(()=>
				{
					for(int Pixel = WriteStart; Pixel < WriteEnd; Pixel++)
					{
						int PixelX = Pixel % BitmapWidth;
						int PixelY = Pixel / BitmapHeight;
						float X = MathUtil.Lerp(Config.DepthMin, Config.DepthMax, (float)PixelX / BitmapWidth);
						float Y = MathUtil.Lerp(Config.WidthMin, Config.WidthMax, (float)PixelY / BitmapHeight);
						float Height = ObjData.GetHeight(X, Y);

						// コンソールにも出力.
						string LogOutput = "X:" + X + " Y:" + Y;
						if(Height != Config.HeightMin)
						{
							LogOutput += " Height:" + Height;
						}
						Console.WriteLine(LogOutput);
					}
				});
				TaskList.Add(WriteTask);
				WriteTask.Start();
			}
			
			while(true)
			{
				bool bAllEnd = true;
				for(int i = 0; i < TaskList.Count; i++)
				{
					if(!TaskList[i].IsCompleted)
					{
						bAllEnd = false;
						break;
					}
				}

				if (bAllEnd) { break; }
			}

			string BmpFilePath = Config.BitMapDirectory + "\\" + Path.GetFileNameWithoutExtension(ObjFilePath) + ".bmp";
			Bmp.Save(BmpFilePath);

			return true;
		}

	}
}
