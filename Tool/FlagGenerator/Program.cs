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
				return;
			}

			// enumソース生成.
			HeaderGenerator HeaderGen = new HeaderGenerator(Parser.Flags);
			HeaderGen.Generate();

			string ServerPath = "..\\..\\Server\\AnpanMMOServer\\Script\\ScriptFlag.h";
			using (StreamWriter Writer = new StreamWriter(ServerPath, false))
			{
				Writer.Write(HeaderGen.Code);
			}

			string ClientPath = "..\\..\\Client\\AnpanMMO\\Source\\AnpanMMO\\Script\\ScriptFlag.h";
			using (StreamWriter Writer = new StreamWriter(ClientPath, false))
			{
				Writer.Write(HeaderGen.Code);
			}
		}
	}
}
