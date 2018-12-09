using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptTransporter
{

	/// <summary>
	/// 設定クラス
	/// </summary>
	public class Config
	{

		/// <summary>
		/// 転送先データが格納されるディレクトリ名.
		/// </summary>
		public static readonly string TransportSettingFileDirectory = "Targets";

		/// <summary>
		/// 一時ディレクトリ名.
		/// </summary>
		public static readonly string TemporaryDirectory = "Tmp";

		/// <summary>
		/// スクリプトディレクトリ名.
		/// </summary>
		public static readonly string ScriptDirectory = "Scripts";

	}
}
