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
		/// カラムリスト
		/// </summary>
		private List<Column> Columns;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		/// <param name="InColumns">カラムリスト</param>
		public SQLGenerator(string InFilePath, List<Column> InColumns)
		{
			FilePath = InFilePath;
			Columns = InColumns;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			// ファイル名をテーブル名として扱う。
			string TableName = Path.GetFileNameWithoutExtension(FilePath);
			var Writer = new StreamWriter(FilePath, false);
			Writer.WriteLine("DROP TABLE IF EXISTS `" + TableName + "`;");
			Writer.WriteLine("CREATE TABLE `" + TableName + "` (");
			foreach(Column Col in Columns)
			{
				string Line = " `" + Col.Name + "` ";
				Line += GetSQLTypeName(Col.DataType) + ",";
				Writer.WriteLine(Line);
			}
			Writer.WriteLine("PRIMARY KEY(`" + Columns[0].Name + "`)\n);");

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
			for(int i = 0; ; i++)
			{
				string Line = "INSERT INTO `" + TableName + "` VALUES (";
				bool bFinished = false;
				foreach (Column Col in Columns)
				{
					if(i >= Col.DataList.Count)
					{
						bFinished = true;
						break;
					}
					string Data = Col.DataList[i].ToString();
					if(Col.DataType == Type.String)
					{
						Data = "'" + Data + "'";
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
