using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{

	/// <summary>
	///	ユーティリティクラス
	/// </summary>
	public class Util
	{

		/// <summary>
		/// ローカルホストか？
		/// </summary>
		/// <param name="Host">ホスト</param>
		/// <returns>ローカルホストならtrueを返す。</returns>
		public static bool IsLocalHost(string Host)
		{
			return (Host == "localhost" || Host == "127.0.0.1");
		}

		/// <summary>
		/// 型を文字列にして返す。
		/// </summary>
		/// <param name="InType">タイプ</param>
		/// <returns>型の文字列</returns>
		public static string ToTypeNameString(Type InType)
		{
			string TypeName = "";

			switch(InType)
			{
				case Type.String:

					TypeName = "std::string";
					break;

				case Type.Float:

					TypeName = "float";
					break;

				default:

					// 横着.
					TypeName = InType.ToString();
					break;
			}
			
			return TypeName;
		}

	}
}
