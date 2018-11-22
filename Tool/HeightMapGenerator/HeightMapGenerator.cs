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
		/// .objファイルのパス
		/// </summary>
		private string ObjFilePath;

		/// <summary>
		/// objファイル読み込み
		/// </summary>
		private ObjFile ObjData;

		/// <summary>
		/// 書き込みプログレスフォーム
		/// </summary>
		private WriteProgressForm ProgressForm;
		
		/// <summary>
		/// コンストラクタ
		/// </summary>ask
		/// <param name="InObjFilePath">.objのファイルパス</param>
		public HeightMapGenerator(string InObjFilePath)
		{
			ObjFilePath = InObjFilePath;
			ObjData = new ObjFile(ObjFilePath);
			ProgressForm = new WriteProgressForm();
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

			ProgressForm.Show();
			
			Bitmap Bmp = new Bitmap(BitmapWidth, BitmapHeight);
			int BmpSize = BitmapWidth * BitmapHeight;

			ProgressForm.SetWriteDataSize(BmpSize);
			
			for(int PixelX = 0; PixelX < BitmapWidth; PixelX++)
			{
				for(int PixelY = 0; PixelY < BitmapHeight; PixelY++)
				{
					float X = MathUtil.Lerp(Config.DepthMin, Config.DepthMax, (float)PixelX / BitmapWidth);
					float Y = MathUtil.Lerp(Config.WidthMin, Config.WidthMax, (float)PixelY / BitmapHeight);
					float Height = ObjData.GetHeight(X, Y);

					// 色データに変換して書き込み。
					Color HeightColor = HeightToColor(Height);
					Bmp.SetPixel(PixelX, PixelY, HeightColor);

					// プログレスバー更新.
					ProgressForm.SetProgress(PixelX * BitmapHeight + PixelY);
				}
			}

			string BmpFilePath = Config.BitMapDirectory + "\\" + Path.GetFileNameWithoutExtension(ObjFilePath) + ".bmp";
			Bmp.Save(BmpFilePath);

			ProgressForm.Close();

			return true;
		}

		/// <summary>
		/// 高さデータを色データに変換.
		/// </summary>
		/// <param name="Height">高さ</param>
		/// <returns>色データ</returns>
		private Color HeightToColor(float Height)
		{
			float Rate = 1.0f - (Height - Config.HeightMax) / (Config.HeightMin - Config.HeightMax);
			int B = (int)(255 * Rate);
			Color Col = Color.FromArgb(0, 0, B);
			return Col;
		}

	}
}
