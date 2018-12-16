using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NativePacketGenerator
{
	/// <summary>
	/// PacketID.hを生成するクラス
	/// </summary>
	public class IDEnumGenerator
	{
		/// <summary>
		/// テンプレートファイル名.
		/// </summary>
		private static readonly string TemplateFileName = "templates\\PacketID.h";

		/// <summary>
		/// クラス群.
		/// </summary>
		private List<ClassData> Classes = new List<ClassData>();

		/// <summary>
		/// 置換結果.
		/// </summary>
		private string Result = "";

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InClasses">クラス群</param>
		public IDEnumGenerator(List<ClassData> InClasses)
		{
			Classes = InClasses;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrue</returns>
		public bool Generate()
		{
			try
			{
				StreamReader Reader = new StreamReader(TemplateFileName);
				Result = Reader.ReadToEnd();
				string IDs = "";
				foreach(var Class in Classes)
				{
					if(!Class.IsPureClass)
					{
						IDs += Class.PacketID + ",\n\t\t";
					}
				}
				Result = Result.Replace("$PACKET_ID_LIST$", IDs);
				Reader.Close();
			}
			catch(Exception e)
			{
				Console.Error.WriteLine(e.Message);
				return false;
			}

			return true;
		}

		/// <summary>
		/// 書き出し。
		/// Generate()実行後に走らせること。
		/// </summary>
		/// <param name="TargetPath">対象パス</param>
		/// <returns>成功したらtrue</returns>
		public bool Write(string TargetPath)
		{
			try
			{
				string FullPath = Path.GetFullPath(TargetPath);
				StreamWriter Writer = new StreamWriter(FullPath);
				Writer.Write(Result);
				Writer.Close();
			}
			catch(Exception e)
			{
				Console.Error.WriteLine(e.Message);
				return false;
			}

			return true;
		}

	}
}
