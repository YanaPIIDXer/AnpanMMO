using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace HeightMapGenerator
{

	/// <summary>
	/// 書き込みプログレスフォーム
	/// </summary>
	public partial class WriteProgressForm : Form
	{

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public WriteProgressForm()
		{
			InitializeComponent();
			WriteProgressBar.Value = 0;
		}

		/// <summary>
		/// 書き込みデータ長のセット
		/// </summary>
		/// <param name="Size">データ長</param>
		public void SetWriteDataSize(int Size)
		{
			WriteProgressBar.Maximum = Size;
		}

		/// <summary>
		/// 進捗をセット
		/// </summary>
		/// <param name="Value">進捗</param>
		public void SetProgress(int Value)
		{
			WriteProgressBar.Value = Value;
		}
	}
}
