using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{

	/// <summary>
	/// カラム
	/// </summary>
	public class Column
	{

		/// <summary>
		/// カラム名.
		/// </summary>
		public string Name { get; private set; }

		/// <summary>
		/// データ型.
		/// </summary>
		public Type DataType { get; private set; }

		/// <summary>
		/// データリスト
		/// </summary>
		public List<object> DataList { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InName">カラム名</param>
		/// <param name="InDataType">データ型</param>
		public Column(string InName, Type InDataType)
		{
			Name = InName;
			DataType = InDataType;
			DataList = new List<object>();
		}

		/// <summary>
		/// データ追加.
		/// </summary>
		/// <param name="Data">データ</param>
		public void AddData(object Data)
		{
			DataList.Add(Data);
		}

	}
}
