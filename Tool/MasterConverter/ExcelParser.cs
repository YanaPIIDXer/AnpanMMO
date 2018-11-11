using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using OfficeOpenXml;

namespace MasterConverter
{

	/// <summary>
	/// Excelパーサ
	/// </summary>
	public class ExcelParser
	{

		/// <summary>
		/// $ITEMタグを見つけるまでの深さ
		/// </summary>
		private static readonly int CheckDepth = 10;

		/// <summary>
		/// $ITEMタグを探し始める行.
		/// </summary>
		private static readonly int CheckStartRow = 3;

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// カラムリスト
		/// </summary>
		private List<Column> Columns = new List<Column>();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		public ExcelParser(string InFilePath)
		{
			FilePath = InFilePath;
		}

		/// <summary> 0
		/// ロード
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Load()
		{
			using (var Excel = new ExcelPackage(new FileInfo(FilePath)))
			{
				var WorkSheet = Excel.Workbook.Worksheets[1];
				int TagIndex = FindItemTag(WorkSheet);
				if(TagIndex == -1) { return false; }

				CollectColumns(WorkSheet, TagIndex - 2);
				for(int i = 0; i < Columns.Count; i++)
				{
					Console.WriteLine(Columns[i].Name + ":" + Columns[i].DataType.ToString());
				}
			}

			return true;
		}

		/// <summary>
		/// $ITEMタグを探索.
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		/// <returns>行のインデックス。見つからなかった場合は-1を返す。</returns>
		private int FindItemTag(ExcelWorksheet WorkSheet)
		{
			for(int i = CheckStartRow; i < CheckStartRow + CheckDepth; i++)
			{
				if((string)WorkSheet.Cells[i, 1].Value == "$ITEM") { return i; }
			}
			return -1;
		}

		/// <summary>
		/// カラムをリストアップする。
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		/// <param name="StartRow">開始する行</param>
		private void CollectColumns(ExcelWorksheet WorkSheet, int StartRow)
		{
			for(int i = 2; ; i++)
			{
				string ColumnName = (string) WorkSheet.Cells[StartRow, i].Value;
				if (String.IsNullOrEmpty(ColumnName)) { return; }
				string DataTypeName = (string)WorkSheet.Cells[StartRow + 1, i].Value;
				Type DataType = Type.String;
				switch(DataTypeName)
				{
					case "s8":

						DataType = Type.s8;
						break;

					case "u8":

						DataType = Type.u8;
						break;

					case "s16":

						DataType = Type.s16;
						break;

					case "u16":

						DataType = Type.u16;
						break;

					case "s32":

						DataType = Type.s32;
						break;

					case "u32":

						DataType = Type.u32;
						break;

					case "string":

						DataType = Type.String;
						break;
				}

				Column NewColumn = new Column(ColumnName, DataType);
				Columns.Add(NewColumn);
			}
		}

	}
}
