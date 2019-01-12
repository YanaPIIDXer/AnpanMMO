using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CopyrightConverter
{
	class Program
	{

		/// <summary>
		/// ソースディレクトリへのパス
		/// </summary>
		private static readonly string SourceDirectoryPath = "..\\..\\..\\..\\Client\\AnpanMMO\\Source\\";

		/// <summary>
		/// 古いコピーライト
		/// </summary>
		private static readonly string OldCopyRight = "Copyright 2018 YanaPIIDXer All Rights Reserved.";

		/// <summary>
		/// 新しいコピーライト
		/// </summary>
		private static readonly string NewCopyRight = "Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.";

		static void Main(string[] args)
		{
			List<string> Files = new List<string>();
			Files.AddRange(Directory.GetFiles(SourceDirectoryPath, "*.cpp", SearchOption.AllDirectories));
			Files.AddRange(Directory.GetFiles(SourceDirectoryPath, "*.h", SearchOption.AllDirectories));
			foreach(var FilePath in Files)
			{
				string Source = "";
				using (StreamReader Reader = new StreamReader(FilePath))
				{
					Source = Reader.ReadToEnd();
				}
				Source = Source.Replace(OldCopyRight, NewCopyRight);
				using (StreamWriter Writer = new StreamWriter(FilePath, false))
				{
					Writer.Write(Source);
				}
			}
		}
	}
}
