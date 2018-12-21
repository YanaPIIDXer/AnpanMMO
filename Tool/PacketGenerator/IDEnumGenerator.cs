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
		/// <param name="IDShiftCount">IDをシフトさせるビット数</param>
		/// <param name="ScopeName">スコープ名</param>
		/// <returns>成功したらtrue</returns>
		public bool Generate(int IDShiftCount, string ScopeName)
		{
			try
			{
				StreamReader Reader = new StreamReader(TemplateFileName, Encoding.GetEncoding("Shift-JIS"));
				Result = Reader.ReadToEnd();
				Result = Result.Replace("$SCOPE_NAME$", ScopeName);
				string IDs = "";
				byte Count = (byte)(1 << IDShiftCount);
				foreach(var Class in Classes)
				{
					if(!Class.IsPureClass)
					{
						IDs += "//! " + Class.Comment + "\n\t\t";
						string Str = Class.PacketID + " = " + string.Format("0x{0:X2}", Count);
						IDs += Str + ",\n\t\t";
						Count++;
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
				StreamWriter Writer = new StreamWriter(FullPath, false, Encoding.GetEncoding("Shift-JIS"));

				// インクルードガードはここで置換する。
				Result = Result.Replace("$INCLUDE_GUARD$", "__" + Path.GetFileNameWithoutExtension(TargetPath).ToUpper() + "_H__");

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
