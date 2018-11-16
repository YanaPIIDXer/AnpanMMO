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
		/// タグを検索する深さ
		/// </summary>
		private static readonly int CheckDepth = 15;

		/// <summary>
		/// $ITEMタグを探し始める行.
		/// </summary>
		private static readonly int CheckStartRow = 1;

		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// マスタデータ
		/// </summary>
		public MasterData Master { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		public ExcelParser(string InFilePath)
		{
			FilePath = InFilePath;
			Master = new MasterData(Path.GetFileNameWithoutExtension(InFilePath));
		}

		/// <summary> 0
		/// ロード
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Load()
		{
			try
			{
				using (var Excel = new ExcelPackage(new FileInfo(FilePath)))
				{
					var WorkSheet = Excel.Workbook.Worksheets[1];
					CheckTags(WorkSheet);

					int TagIndex = FindItemTag(WorkSheet);
					if (TagIndex == -1) { return false; }

					CollectColumns(WorkSheet, TagIndex - 2);
					if (Master.GetColumn(0).DataType == Type.String)
					{
						Console.WriteLine("最初の行を文字列型にすることは出来ません。");
						return false;
					}

					CollectDatas(WorkSheet, TagIndex);
				}
			}
			catch(Exception e)
			{
				Console.WriteLine("");
				Console.WriteLine(e.Message);
				return false;
			}
			return true;
		}

		/// <summary>
		/// タグのチェック
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		private void CheckTags(ExcelWorksheet WorkSheet)
		{
			for(int i = 1; i < 1 + CheckDepth; i++)
			{
				try
				{
					string CellValue = (string)WorkSheet.Cells[i, 1].Value;

					// オートキー
					if(CellValue == "$AUTO_KEY")
					{
						Master.SetEnableAutoKey();
					}
				}
				catch {}
			}
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

					case "float":

						DataType = Type.Float;
						break;

					case "String":

						DataType = Type.String;
						break;

					default:

						throw new Exception(DataTypeName + "は認識できない型です。");
				}

				Column NewColumn = new Column(ColumnName, DataType);
				Master.AddColumn(NewColumn);
			}
		}

		/// <summary>
		/// データを収集.
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		/// <param name="StartRow">開始行</param>
		private void CollectDatas(ExcelWorksheet WorkSheet, int StartRow)
		{
			for(int i = StartRow; ; i++)
			{
				for(int j = 1; j <= Master.GetColumnCount(); j++)
				{
					object Data = WorkSheet.Cells[i, j + 1].Value;
					if(j == 1 && Data == null) { return; }
					Master.AddDataToColumn(j - 1, Data);
				}
			}
		}

	}
}
