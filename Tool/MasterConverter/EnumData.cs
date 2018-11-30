using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{

	/// <summary>
	/// Enumのデータ
	/// </summary>
	public class EnumData
	{

		/// <summary>
		/// 要素リスト
		/// </summary>
		public Dictionary<string, int> EnumList { get; private set; }		

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public EnumData()
		{
			EnumList = new Dictionary<string, int>();
		}

		/// <summary>
		/// 追加.
		/// </summary>
		/// <param name="Name">Enum名</param>
		/// <param name="Value">値</param>
		public void Add(string Name, int Value)
		{
			EnumList.Add(Name, Value);
		}

	}
}
