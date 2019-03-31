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
					if (Class.IsPureClass) { continue; }
					if(Class.IsForCacheServer)
					{
						Class.Includes.Add("CacheServerPacketID.h");
					}
					else if(Class.IsForWordCheckServer)
					{
						Class.Includes.Add("WordCheckServerPacketID.h");
					}
					else
					{
						Class.Includes.Add("PacketID.h");
					}
				}
			}

			// ゲームサーバ、クライアント
			List<ClassData> GameServerClasses = new List<ClassData>(from Class in Classes where	(!Class.IsForCacheServer && !Class.IsForWordCheckServer) select Class);
			IDEnumGenerator GameServerIDGen = new IDEnumGenerator(GameServerClasses);
			if (!GameServerIDGen.Generate(0, "PacketID")) { return; }
			if (!GameServerIDGen.Write(ServerPath + "\\PacketID.h")) { return; }
			if (!GameServerIDGen.Write(ClientPath + "\\PacketID.h")) { return; }

			// キャッシュサーバ
			List<ClassData> CacheServerClasses = new List<ClassData>(from Class in Classes where (Class.IsForCacheServer) select Class);
			IDEnumGenerator CacheServerIDGen = new IDEnumGenerator(CacheServerClasses);
			if (!CacheServerIDGen.Generate(6, "CachePacketID")) { return; }
			if (!CacheServerIDGen.Write(ServerPath + "\\CacheServerPacketID.h")) { return; }
			if (!CacheServerIDGen.Write(CacheServerPath + "\\CacheServerPacketID.h")) { return; }

			// ワードチェックサーバ
			List<ClassData> WordCheckServerClasses = new List<ClassData>(from Class in Classes where (Class.IsForWordCheckServer) select Class);
			IDEnumGenerator WordCheckServerIDGen = new IDEnumGenerator(WordCheckServerClasses);
			if (!WordCheckServerIDGen.Generate(7, "WordCheckPacketID")) { return; }
			if (!WordCheckServerIDGen.Write(ServerPath + "\\WordCheckServerPacketID.h")) { return; }
			if (!WordCheckServerIDGen.Write(WordCheckServerPath + "\\WordCheckServerPacketID.h")) { return; }

			foreach (var Class in Classes)
			{
				SourceGenerator Gen = new SourceGenerator(Class);
				Console.WriteLine(Class.ClassName + "の出力中・・・");
				if (!Gen.Generate())
				{
					Console.WriteLine("ソースコードの生成に失敗しました。");
					return;
				}
				if (!Gen.Write(ServerPath))
				{
					Console.WriteLine("ゲームサーバへのソースコード書き込みに失敗しました。");
					return;
				}
				if (!Class.IsForCacheServer && !Class.IsForWordCheckServer)
				{
					// クライアント
					if (!Gen.Write(ClientPath))
					{
						Console.WriteLine("クライアントへのソースコード書き込みに失敗しました。");
						return;
					}
				}
				else if (Class.IsForCacheServer)
				{
					// キャッシュサーバ
					if (!Gen.Write(CacheServerPath))
					{
						Console.WriteLine("キャッシュサーバへのソースコード書き込みに失敗しました。");
						return;
					}
				}
				else
				{
					// ワードチェックサーバ
					if (!Gen.Write(WordCheckServerPath))
					{
						Console.WriteLine("ワードチェックサーバへのソースコード書き込みに失敗しました。");
						return;
					}
				}
			}

		}
	}
}
