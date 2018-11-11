using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{
	class Program
	{
		static void Main(string[] args)
		{
			ExcelParser Parser = new ExcelParser("MasterData\\Test.xlsx");
			if(!Parser.Load())
			{
				Console.WriteLine("Excelファイルの解析に失敗しました。");
				Console.ReadKey();
			}

			SQLGenerator SQLGen = new SQLGenerator("SQLs\\Test.sql", Parser.Columns);
			if(!SQLGen.Generate())
			{
				Console.WriteLine("SQLファイルの生成に失敗しました。");
				Console.ReadKey();
			}

		}
	}
}
