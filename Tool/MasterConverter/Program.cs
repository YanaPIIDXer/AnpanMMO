﻿using System;
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
			Parser.Load();
		}
	}
}
