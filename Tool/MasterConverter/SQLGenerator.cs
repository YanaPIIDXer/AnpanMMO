using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// SQLの生成.
	/// </summary>
	public class SQLGenerator
	{

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// マスタデータ
		/// </summary>
		private MasterData Master;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		/// <param name="InMaster">マスタデータ</param>
		public SQLGenerator(string InFilePath, MasterData InMaster)
		{
			FilePath = InFilePath;
			Master = InMaster;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			// ファイル名をテーブル名として扱う。
			string TableName = Path.GetFileNameWithoutExtension(FilePath);

			var Dir = Path.GetDirectoryName(FilePath);
			if(!Directory.Exists(Dir))
			{
				Directory.CreateDirectory(Dir);
			}

			var Writer = File.CreateText(FilePath);
			Writer.WriteLine("DROP TABLE IF EXISTS `" + TableName + "`;");
			Writer.WriteLine("CREATE TABLE `" + TableName + "` (");
			if(Master.IsMultipleSheet)
			{
				Writer.WriteLine(" `SheetIndex` INT UNSIGNED,");
			}
			var Columns = Master.GetColumns(0);
			for(int i = 0; i < Columns.Count; i++)
			{
				Column Col = Columns[i];
				string Line = " `" + Col.Name + "` ";
				Line += GetSQLTypeName(Col.DataType);
				if (i < Columns.Count - 1)
				{
					Line += ",";
				}
				Writer.WriteLine(Line);
			}
			Writer.WriteLine(") DEFAULT CHARSET=utf8;");

			Writer.WriteLine("LOCK TABLES `" + TableName + "` WRITE;");

			WriteInsert(Writer, TableName);
			
			Writer.WriteLine("UNLOCK TABLES;");

			Writer.Close();
			return true;
		}

		/// <summary>
		/// SQLで扱う型名を取得.
		/// </summary>
		/// <param name="InType"></param>
		/// <returns></returns>
		private string GetSQLTypeName(Type InType)
		{
			string TypeName = "";

			switch(InType)
			{
				case Type.s8:

					TypeName = "TINYINT";
					break;

				case Type.u8:

					TypeName = "TINYINT UNSIGNED";
					break;

				case Type.s16:

					TypeName = "SMALLINT";
					break;

				case Type.u16:

					TypeName = "SMALLINT　UNSIGNED";
					break;

				case Type.s32:

					TypeName = "INT";
					break;

				case Type.u32:

					TypeName = "INT UNSIGNED";
					break;

				case Type.String:
				
					TypeName = "TEXT";
					break;

				case Type.Float:

					TypeName = "FLOAT";
					break;
			}

			return TypeName;
		}

		/// <summary>
		/// INSERT文を出力.
		/// </summary>
		/// <param name="Writer">ストリーム</param>
		/// <param name="TableName">テーブル名</param>
		private void WriteInsert(StreamWriter Writer, string TableName)
		{
			for(int Sheet = 0; Sheet < Master.SheetCount; Sheet++)
			{
				for (int i = 0; ; i++)
				{
					string Line = "INSERT INTO `" + TableName + "` VALUES (";
					bool bFinished = false;
					if (Master.IsMultipleSheet)
					{
						Line += Sheet + ",";
					}
					var Columns = Master.GetColumns(Sheet);
					foreach (Column Col in Columns)
					{
						if (i >= Col.DataList.Count)
						{
							bFinished = true;
							break;
						}
						string Data = Col.DataList[i].ToString();
						int EnumValue = 0;
						if (Col.DataType == Type.String)
						{
							Data = "'" + Data + "'";
						}
						else if (Master.TryFindEnumValue(Data, out EnumValue))
						{
							Data = EnumValue.ToString();
						}

						Line += Data;
						Line += ",";
					}
					if (bFinished) { break; }
					Line = Line.Substring(0, Line.Length - 1);
					Line += ");";
					Writer.WriteLine(Line);
				}
			}
		}
	}
}
