using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NativePacketGenerator
{
	class Program
	{
		/// <summary>
		/// 設定ファイル名.
		/// </summary>
		private static readonly string SettingFileName = "NativePacketGenerator.ini";

		static void Main(string[] args)
		{
			if(!File.Exists(SettingFileName))
			{
				StreamWriter Writer = new StreamWriter(SettingFileName);
				Writer.WriteLine("Server Directory:");
				Writer.WriteLine("Client Directory:");
				Writer.WriteLine("CacheServer Directory:");
				Writer.WriteLine("WordCheckServer Directory:");
				Writer.Close();
				Console.WriteLine("設定ファイルが存在しなかったので自動生成しました。\n必要な項目を入力してください。");
				return;
			}

			StreamReader Reader = new StreamReader(SettingFileName);
			var ServerPath = Reader.ReadLine().Replace("Server Directory:", "");
			var ClientPath = Reader.ReadLine().Replace("Client Directory:", "");
			var CacheServerPath = Reader.ReadLine().Replace("CacheServer Directory:", "");
			var WordCheckServerPath = Reader.ReadLine().Replace("WordCheckServer Directory:", "");

			var Excels = Directory.GetFiles("PacketData");
			List<ClassData> Classes = new List<ClassData>();
			foreach(var Excel in Excels)
			{
				ExcelParser Parser = new ExcelParser(Excel);
				if(!Parser.Parse())
				{
					Console.Error.WriteLine(Excel + "のパースに失敗しました。");
					return;
				}
				foreach(var Class in Parser.Classes)
				{
					Classes.Add(Class);
				}
			}

			IDEnumGenerator IDGen = new IDEnumGenerator(Classes);
			if (!IDGen.Generate()) { return; }
			if (!IDGen.Write(ServerPath + "\\PacketID.h")) { return; }
			if (!IDGen.Write(ClientPath + "\\PacketID.h")) { return; }
			if (!IDGen.Write(CacheServerPath + "\\PacketID.h")) { return; }
			if (!IDGen.Write(WordCheckServerPath + "\\PacketID.h")) { return; }

			foreach(var Class in Classes)
			{
				SourceGenerator Gen = new SourceGenerator(Class);
				if (!Gen.Generate()) { return; }
				if (!Gen.Write(ServerPath)) { return; }
				if (!Class.IsForCacheServer && !Class.IsForWordCheckServer)
				{
					// クライアント
					if (!Gen.Write(ClientPath)) { return; }
				}
				else if (Class.IsForCacheServer)
				{
					// キャッシュサーバ
					if (!Gen.Write(CacheServerPath)) { return; }
				}
				else
				{
					// ワードチェックサーバ
					if (!Gen.Write(WordCheckServerPath)) { return; }
				}
			}

		}
	}
}
