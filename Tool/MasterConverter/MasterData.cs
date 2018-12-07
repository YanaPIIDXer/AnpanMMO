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
		/// Enumリスト
		/// </summary>
		public List<EnumData> EnumList { get; private set; }

		/// <summary>
		/// オートキー？
		/// </summary>
		public bool IsAutoKey { get; private set; }

		/// <summary>
		/// サーバのみ出力するか？
		/// </summary>
		public bool IsServerOnly { get; private set; }

		/// <summary>
		/// クライアントのみ出力するか？
		/// </summary>
		public bool IsClientOnly { get; private set; }

		/// <summary>
		/// ワードチェックサーバ向けに出力するか？
		/// </summary>
		public bool IsForWordCheckServer { get; private set; }
		
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InName">マスタ名</param>
		public MasterData(string InName)
		{
			Name = InName;
			IsAutoKey = false;
			IsServerOnly = false;
			IsClientOnly = false;
			IsForWordCheckServer = false;
			EnumList = new List<EnumData>();
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
		/// Enumデータを追加。
		/// </summary>
		/// <param name="Data">Enumデータ</param>
		public void AddEnum(EnumData Data)
		{
			EnumList.Add(Data);
		}

		/// <summary>
		/// Enumの値の取得を試みる
		/// </summary>
		/// <param name="EnumName">Enum名</param>
		/// <param name="Value">値</param>
		/// <returns>存在すればtrue</returns>
		public bool TryFindEnumValue(string EnumName, out int Value)
		{
			Value = 0;
			foreach(var Enum in EnumList)
			{
				foreach(var Data in Enum.EnumList)
				{
					if(EnumName == Data.Key)
					{
						Value = Data.Value;
						return true;
					}
				}
			}

			return false;
		}

		/// <summary>
		/// オートキーを設定.
		/// </summary>
		public void SetEnableAutoKey()
		{
			IsAutoKey = true;
		}

		/// <summary>
		/// サーバのみ出力を設定.
		/// </summary>
		public void SetEnableServerOnly()
		{
			IsServerOnly = true;
		}

		/// <summary>
		/// クライアントのみ出力を設定.
		/// </summary>
		public void SetEnableClientOly()
		{
			IsClientOnly = true;
		}

		/// <summary>
		/// ワードチェックサーバ向けへの出力を設定.
		/// </summary>
		public void SetForWordCheckServer()
		{
			IsForWordCheckServer = true;

			// サーバのみの出力とする。
			IsServerOnly = true;
		}

		/// <summary>
		/// オートキーの生成.
		/// </summary>
		public void GenerateAutoKey()
		{
			if (!IsAutoKey) { return; }
			Column AutoKeyColumn = new Column("AutoKey", Type.s32);
			int Index = 1;
			if(Columns.Count == 1) { Index = 0; }
			for(int i = 0;i < Columns[Index].DataList.Count; i++)
			{
				AutoKeyColumn.DataList.Add((double)(i + 1));
			}
			Columns.Insert(0, AutoKeyColumn);
		}
		
	}
}
