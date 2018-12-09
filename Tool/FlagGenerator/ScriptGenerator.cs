using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FlagGenerator
{

	/// <summary>
	/// スクリプト生成.
	/// </summary>
	public class ScriptGenerator
	{

		/// <summary>
		/// ファイルパス
		/// </summary>
		private static readonly string FilePath = "..\\Scripts\\Flags.lua";

		/// <summary>
		/// フラグリスト
		/// </summary>
		private List<FlagData> FlagList;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFlagList">フラグリスト</param>
		public ScriptGenerator(List<FlagData> InFlagList)
		{
			FlagList = InFlagList;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			try
			{
				using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.UTF8))
				{
					foreach(var Data in FlagList)
					{
						Writer.WriteLine(Data.Name + " = " + Data.Value);
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
