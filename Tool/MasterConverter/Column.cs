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

		/// <summary>
		/// 同じものか？
		/// </summary>
		/// <param name="obj">オブジェクト</param>
		/// <returns>同じものならtrueを返す</returns>
		public override bool Equals(object obj)
		{
			return base.Equals(obj);
		}

		/// <summary>
		/// ハッシュコードを取得
		/// </summary>
		/// <returns>ハッシュコード</returns>
		public override int GetHashCode()
		{
			return base.GetHashCode();
		}

		/// <summary>
		/// ==
		/// </summary>
		/// <param name="A">A</param>
		/// <param name="B">B</param>
		/// <returns>同じものならtrue</returns>
		public static bool operator ==(Column A, Column B)
		{
			return ((A.Name == B.Name) && (A.DataType == B.DataType));
		}

		/// <summary>
		/// !=
		/// </summary>
		/// <param name="A">A</param>
		/// <param name="B">B</param>
		/// <returns>別物ならtrue</returns>
		public static bool operator !=(Column A, Column B)
		{
			return ((A.Name != B.Name) || (A.DataType != B.DataType));
		}

	}
}
