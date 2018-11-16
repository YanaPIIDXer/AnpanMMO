using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{

	/// <summary>
	/// マスタデータクラス
	/// </summary>
	public class MasterData
	{

		/// <summary>
		/// マスタ名.
		/// </summary>
		public string Name { get; private set; }

		/// <summary>
		/// カラムリスト
		/// </summary>
		private List<Column> Columns = new List<Column>();

		/// <summary>
		/// オートキー？
		/// </summary>
		public bool IsAutoKey { get; private set; }
		
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InName">マスタ名</param>
		public MasterData(string InName)
		{
			Name = InName;
			IsAutoKey = false;
		}

		/// <summary>
		/// カラムリスト取得.
		/// </summary>
		/// <returns>カラムリスト</returns>
		public List<Column> GetColumns()
		{
			List<Column> Return = new List<Column>();
			foreach(var Col in Columns)
			{
				Return.Add(Col);
			}
			return Return;
		}

		/// <summary>
		/// カラム数を取得.
		/// </summary>
		/// <returns>カラム数</returns>
		public int GetColumnCount()
		{
			return Columns.Count;
		}

		/// <summary>
		/// カラム追加。
		/// </summary>
		/// <param name="NewColumn">新しいカラム</param>
		public void AddColumn(Column NewColumn)
		{
			Columns.Add(NewColumn);
		}

		/// <summary>
		/// カラムを取得.
		/// </summary>
		/// <param name="Index">インデックス</param>
		/// <returns>カラム</returns>
		public Column GetColumn(int Index)
		{
			return Columns[Index];
		}

		/// <summary>
		/// カラムにデータ追加。
		/// </summary>
		/// <param name="ColumnIndex">カラムインデックス</param>
		/// <param name="Data">データ</param>
		public void AddDataToColumn(int ColumnIndex, object Data)
		{
			Columns[ColumnIndex].DataList.Add(Data);
		}

		/// <summary>
		/// オートキーを設定。
		/// </summary>
		public void SetEnableAutoKey()
		{
			IsAutoKey = true;
		}

		/// <summary>
		/// オートキーの生成.
		/// </summary>
		public void GenerateAutoKey()
		{
			if (!IsAutoKey) { return; }
			Column AutoKeyColumn = new Column("AutoKey", Type.s32);
			for(int i = 0;i < Columns[1].DataList.Count; i++)
			{
				AutoKeyColumn.DataList.Add((double)(i + 1));
			}
			Columns.Insert(0, AutoKeyColumn);
		}
		
	}
}
