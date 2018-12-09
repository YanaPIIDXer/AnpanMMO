using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FlagGenerator
{
	class Program
	{
		static void Main(string[] args)
		{
			ExcelParser Parser = new ExcelParser();
			if(!Parser.Read())
			{
				Console.WriteLine("エクセルのパースに失敗しました。");
				Console.ReadKey();
				return;
			}
			
			ScriptGenerator ScriptGen = new ScriptGenerator(Parser.Flags);
			if(!ScriptGen.Generate())
			{
				Console.WriteLine("スクリプトファイルの生成に失敗しました。");
				Console.ReadKey();
				return;
			}

			Console.WriteLine("スクリプトファイルを生成しました。");
			Console.ReadKey();
		}
	}
}
