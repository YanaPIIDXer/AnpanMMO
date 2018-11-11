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

		/// <summary>
		/// .sqlファイルを生成するパス
		/// </summary>
		private static readonly string SQLOutputPath = "SQLs";

		public Form1()
		{
			InitializeComponent();
		}

		// 出力ボタンが押された
		private void OutputButton_Click(object sender, EventArgs e)
		{
			string[] Files = Directory.GetFiles(ExcelFilePath);
			foreach (var TargetFilePath in Files)
			{
				Console.Write(TargetFilePath + "の展開中...");
				ExcelParser Parser = new ExcelParser(TargetFilePath);
				if (!Parser.Load())
				{
					MessageBox.Show("Excelファイルの解析に失敗しました。");
					Console.WriteLine("失敗。");
					return;
				}

				Console.WriteLine("完了。");
				
				string FileName = Path.GetFileNameWithoutExtension(TargetFilePath) + ".sql";
				string FilePath = SQLOutputPath + "\\" + FileName;
				Console.Write(FilePath + "の生成中...");

				SQLGenerator SQLGen = new SQLGenerator(FilePath, Parser.Columns);
				if (!SQLGen.Generate())
				{
					MessageBox.Show("SQLファイルの生成に失敗しました。");
					Console.WriteLine("失敗。");
					return;
				}

				Console.WriteLine("完了。");

				Console.Write(FilePath + "の転送中...");

				// テスト用
				string Host = "";
				string UserName = "";
				string Password = "";
				using (StreamReader Stream = new StreamReader("FTPData.txt"))
				{
					Host = Stream.ReadLine();
					UserName = Stream.ReadLine();
					Password = Stream.ReadLine();
				}

				SQLTransporter Transporter = new SQLTransporter(FilePath, Host, UserName, Password);
				if(!Transporter.Transport())
				{
					MessageBox.Show("SQLファイルの転送に失敗しました。");
					Console.WriteLine("失敗。");
					return;
				}

				Console.WriteLine("完了。");
			}

			MessageBox.Show("出力しました。");
		}
	}
}
