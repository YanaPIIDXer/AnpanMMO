using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OfficeOpenXml;
using System.IO;

namespace NativePacketGenerator
{
	
	/// <summary>
	/// Excel解析.
	/// </summary>
	public class ExcelParser
	{

		/// <summary>
		/// ファイル名.
		/// </summary>
		private string FileName;

		/// <summary>
		/// クラスデータ
		/// </summary>
		public List<ClassData> Classes { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFileName">ファイル名</param>
		public ExcelParser(string InFileName)
		{
			FileName = InFileName;
			Classes = new List<ClassData>();
		}

		/// <summary>
		/// パース
		/// </summary>
		/// <returns>成功したらtrue</returns>
		public bool Parse()
		{
			try
			{
				FileInfo Info = new FileInfo(FileName);
				using(var Excel = new ExcelPackage(Info))
				{
					for(int i = 1; i <= Excel.Workbook.Worksheets.Count; i++)
					{
						var Ws = Excel.Workbook.Worksheets[i];
						if (!ParseSheet(Ws)) { return false; }
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

		/// <summary>
		/// シートのパース
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		/// <returns>成功したらtrue</returns>
		private bool ParseSheet(ExcelWorksheet WorkSheet)
		{
			ClassData Class = null;

			try
			{
				for(int i = 1; !CheckEOF(WorkSheet, i); i++)
				{
					string Tag = (string)WorkSheet.Cells[i, 1].Value;
					switch(Tag)
					{
						case "$CLASS_NAME$":

							Class = new ClassData((string)WorkSheet.Cells[i, 2].Value);
							Class.Comment = WorkSheet.Name + "パケット";
							Classes.Add(Class);
							break;
							
						case "$INCLUDE$":

							Class.AddInclude((string)WorkSheet.Cells[i, 2].Value);
							break;

						case "$BASE_CLASS_NAME$":

							Class.BaseClassName = (string)WorkSheet.Cells[i, 2].Value;
							break;

						case "$PACKET_ID$":

							{
								string PacketID = (string)WorkSheet.Cells[i, 2].Value;
								Class.PacketID = PacketID;
							}
							break;

						case "$ENUM$":

							{
								string TypeName = (string)WorkSheet.Cells[i, 2].Value;
								string Name = (string)WorkSheet.Cells[i, 3].Value;
								string Comment = (string)WorkSheet.Cells[i, 4].Value;
								Class.AddEnum(TypeName, Name, Comment);
							}
							break;

						case "$MEMBER$":

							{
								string TypeName = (string)WorkSheet.Cells[i, 2].Value;
								string MemberName = (string)WorkSheet.Cells[i, 3].Value;
								string Comment = (string)WorkSheet.Cells[i, 4].Value;
								ClassMemberData Data = new ClassMemberData();
								Data.TypeName = TypeName;
								Data.Name = MemberName;
								Data.Comment = Comment;
								Class.AddMember(Data);
							}
							break;

						case "$FOR_CACHE_SERVER$":

							{
								string Value = WorkSheet.Cells[i, 2].Value.ToString();
								if(Value == "1")
								{
									Class.SetForCacheServerFlag();
								}
							}
							break;

						case "$FOR_WORDCHECK_SERVER$":

							{
								string Value = WorkSheet.Cells[i, 2].Value.ToString();
								if(Value == "1")
								{
									Class.SetForWordCheckServerFlag();
								}
							}
							break;
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

		/// <summary>
		/// ファイルの終端かどうかを判定する。
		/// </summary>
		/// <param name="WorkSheet">ワークシート</param>
		/// <param name="Current">現在のインデックス</param>
		/// <returns>終端ならtrue</returns>
		private bool CheckEOF(ExcelWorksheet WorkSheet, int Current)
		{
			for(int i = Current; i < Current + 10; i++)
			{
				if(!string.IsNullOrEmpty((string)WorkSheet.Cells[i, 1].Value)) { return false; }
			}
			return true;
		}

	}
}
