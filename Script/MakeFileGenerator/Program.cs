using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MakeFileGenerator
{
	class Program
	{
		static void Main(string[] args)
		{
			string MakeFile = "";
			using(StreamReader Reader = new StreamReader("makefile_base.txt"))
			{
				MakeFile = Reader.ReadToEnd();
			}

			MakeFile += "\n";

			string[] Sources = Directory.GetFiles("ScriptModule", "*.cpp", SearchOption.AllDirectories);
			foreach(var Source in Sources)
			{
				string ObjFilePath = ".\\obj\\" + Path.GetDirectoryName(Source) + "\\" + Path.GetFileNameWithoutExtension(Source) + ".o";
				MakeFile += ObjFilePath + ": " + Source + "\n";
				MakeFile += "\tif not exist " + Path.GetDirectoryName(ObjFilePath) + " mkdir " + Path.GetDirectoryName(ObjFilePath) + "\n";
				MakeFile += "\t$(COMPILER) -MD $(INCLUDE) -o $@ -c $<\n\n";
			}

			using (StreamWriter Writer = new StreamWriter("makefile"))
			{
				Writer.Write(MakeFile);
			}
		}
	}
}
