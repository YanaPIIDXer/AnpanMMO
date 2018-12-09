using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FlagGenerator
{

	/// <summary>
	/// ヘッダファイルジェネレータ
	/// </summary>
	public class HeaderGenerator
	{

		/// <summary>
		/// 生成されたコード
		/// </summary>
		public string Code { get; private set; }

		/// <summary>
		/// フラグリスト
		/// </summary>
		private List<FlagData> FlagList;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFlagList">フラグリスト</param>
		public HeaderGenerator(List<FlagData> InFlagList)
		{
			FlagList = InFlagList;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		public void Generate()
		{
			// インクルードガード
			Code += "#ifndef __SCRIPTFLAGS_H__\n";
			Code += "#define __SCRIPTFLAGS_H__\n\n";

			Code += "enum EScriptFlags\n{\n";
			foreach(var Data in FlagList)
			{
				Code += "\t" + Data.Name + " = " + Data.Value + ",\n";
			}
			Code += "};\n\n";

			Code += "#endif		// #ifndef __SCRIPTFLAGS_H__\n";
		}

	}
}
