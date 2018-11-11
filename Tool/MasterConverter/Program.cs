using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{
	class Program
	{

		/// <summary>
		/// エクセルファイルを格納するパス
		/// </summary>
		private static readonly string ExcelFilePath = "MasterData";

		static void Main(string[] args)
		{
			string[] Files = Directory.GetFiles(ExcelFilePath);
			foreach(var FilePath in Files)
			{
				ExcelParser Parser = new ExcelParser(FilePath);
				if (!Parser.Load())
				{
					Console.WriteLine("Excelファイルの解析に失敗しました。");
					Console.ReadKey();
				}

				SQLGenerator SQLGen = new SQLGenerator("SQLs\\Test.sql", Parser.Columns);
				if (!SQLGen.Generate())
				{
					Console.WriteLine("SQLファイルの生成に失敗しました。");
					Console.ReadKey();
				}

			}
		}
	}
}
