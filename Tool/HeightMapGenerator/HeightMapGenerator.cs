﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Imaging;

namespace HeightMapGenerator
{

	/// <summary>
	/// ハイトマップ生成クラス
	/// </summary>
	public class HeightMapGenerator
	{

		/// <summary>
		/// objファイル読み込み
		/// </summary>
		private ObjFile ObjData;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ObjFilePath">.objのファイルパス</param>
		public HeightMapGenerator(string ObjFilePath)
		{
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

			return true;
		}

	}
}
