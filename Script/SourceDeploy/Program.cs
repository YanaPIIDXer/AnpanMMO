using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SourceDeploy
{
	class Program
	{
		static void Main(string[] args)
		{
			string SrcPath = "ScriptModule\\Script\\";
			string ServerPath = "..\\..\\Server\\AnpanMMOServer\\Script\\";
			string ClientPath = "..\\..\\Client\\AnpanMMO\\Source\\AnpanMMO\\Script\\";

			string[] Sources = Directory.GetFiles(SrcPath, "*.*", SearchOption.AllDirectories);
			foreach(var Source in Sources)
			{
				// サーバへコピー
				string FileName = Path.GetFileName(Source);
				File.Copy(Source, ServerPath + FileName, true);

				// クライアントへコピー
				File.Copy(Source, ClientPath + FileName, true);
				if (Path.GetExtension(Source) == ".cpp")
				{
					// cppファイルだった場合は先頭の#include "stdafx"を除去。
					string Code = "";
					using (StreamReader Reader = new StreamReader(ClientPath + FileName, Encoding.GetEncoding("Shift-Jis")))
					{
						Code = Reader.ReadToEnd();
					}

					Code = Code.Replace("#include \"stdafx.h\"", "");
					Code = Code.Substring(2);

					using (StreamWriter Writer = new StreamWriter(ClientPath + FileName, false, Encoding.GetEncoding("Shift-Jis")))
					{
						Writer.Write(Code);
					}
				}
				else
				{
					// hファイルだった場合はクラス定義におまじないを追加。
					// ※外部のモジュールにクラスを公開するためのものらしく、
					//   コレがないとリンクエラーになる。
					string Code = "";
					using (StreamReader Reader = new StreamReader(ClientPath + FileName, Encoding.GetEncoding("Shift-Jis")))
					{
						Code = Reader.ReadToEnd();
					}

					Code = Code.Replace("class ", "class SCRIPTMODULE_API ");
					using (StreamWriter Writer = new StreamWriter(ClientPath + FileName, false, Encoding.GetEncoding("Shift-Jis")))
					{
						Writer.Write(Code);
					}
				}
			}

		}
	}
}
