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

namespace MasterConverter
{
	public partial class Form1 : Form
	{

		/// <summary>
		/// エクセルファイルを格納するパス
		/// </summary>
		private static readonly string ExcelFilePath = "MasterData";

		public Form1()
		{
			InitializeComponent();
		}

		// 出力ボタンが押された
		private void OutputButton_Click(object sender, EventArgs e)
		{
			string[] Files = Directory.GetFiles(ExcelFilePath);
			foreach (var FilePath in Files)
			{
				Console.WriteLine(FilePath + "の展開中・・・");
				ExcelParser Parser = new ExcelParser(FilePath);
				if (!Parser.Load())
				{
					MessageBox.Show("Excelファイルの解析に失敗しました。");
					return;
				}

				SQLGenerator SQLGen = new SQLGenerator("SQLs\\Test.sql", Parser.Columns);
				if (!SQLGen.Generate())
				{
					MessageBox.Show("SQLファイルの生成に失敗しました。");
					return;
				}
			}

			MessageBox.Show("出力しました。");
		}
	}
}
