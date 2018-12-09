using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OfficeOpenXml;
using System.IO;

namespace FlagGenerator
{

	/// <summary>
	/// フラグデータ
	/// </summary>
	public class FlagData
	{

		/// <summary>
		/// 名前.
		/// </summary>
		public string Name { get; private set; }

		/// <summary>
		/// 値.
		/// </summary>
		public int Value { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InName">名前</param>
		/// <param name="InValue">値</param>
		public FlagData(string InName, int InValue)
		{
			Name = InName;
			Value = InValue;
		}

	}

	/// <summary> = 
	/// エクセルパーサ
	/// </summary>
	public class ExcelParser
	{

		/// <summary>
		/// ファイル名.
		/// </summary>
		private static readonly string FileName = "Flags.xlsx";

		/// <summary>
		/// フラグリスト
		/// </summary>
		public List<FlagData> Flags { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public ExcelParser()
		{
			Flags = new List<FlagData>();
		}

		/// <summary>
		/// 読み込み.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Read()
		{
			try
			{
				FileInfo Info = new FileInfo(FileName);
				using (ExcelPackage Package = new ExcelPackage(Info))
				{
					ExcelWorksheet Sheet = Package.Workbook.Worksheets[1];

					for(int i = 1; ; i++)
					{
						object NameObj = Sheet.Cells[i, 1].Value;
						if (NameObj == null) { break; }
						FlagData Data = new FlagData(NameObj.ToString(), i);
						Flags.Add(Data);
					}
				}
			}
			catch(Exception e)
			{
				Console.WriteLine(e.Message);
				return false;
			}

			return true;
		}

	}
}
