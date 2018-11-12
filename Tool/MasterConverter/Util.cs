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

	}
}
