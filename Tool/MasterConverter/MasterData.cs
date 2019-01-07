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
		private List<List<Column>> Columns = new List<List<Column>>();

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
		/// 複数シートを使用するか？
		/// </summary>
		public bool IsMultipleSheet { get; private set; }

		/// <summary>
		/// 現在のシートインデックス
		/// </summary>
		public int CurrentSheetIndex { get; set; }

		/// <summary>
		/// シート数.
		/// </summary>
		public int SheetCount { get; private set; }

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
			IsMultipleSheet = false;
			EnumList = new List<EnumData>();
			Columns.Add(new List<Column>());
			CurrentSheetIndex = 0;
			SheetCount = 1;
		}

		/// <summary>
		/// カラムリスト取得.
		/// </summary>
		/// <param name="SheetIndex">シートインデックス</param>
		/// <returns>カラムリスト</returns>
		public List<Column> GetColumns(int SheetIndex)
		{
			List<Column> Return = new List<Column>();
			foreach(var Col in Columns[SheetIndex])
			{
				Return.Add(Col);
			}
			return Return;
		}

		/// <summary>
		/// カラム数を取得.
		/// </summary>
		/// <param name="SheetIndex">シートのインデックス</param>
		/// <returns>カラム数</returns>
		public int GetColumnCount(int SheetIndex)
		{
			return Columns[SheetIndex].Count;
		}

		/// <summary>
		/// カラム追加。
		/// </summary>
		/// <param name="NewColumn">新しいカラム</param>
		public void AddColumn(Column NewColumn)
		{
			Columns[CurrentSheetIndex].Add(NewColumn);
		}

		/// <summary>
		/// カラムを取得.
		/// </summary>
		/// <param name="SheetIndex">シートインデックス</param>
		/// <param name="Index">インデックス</param>
		/// <returns>カラム</returns>
		public Column GetColumn(int SheetIndex, int Index)
		{
			return Columns[SheetIndex][Index];
		}

		/// <summary>
		/// カラムにデータ追加。
		/// </summary>
		/// <param name="ColumnIndex">カラムインデックス</param>
		/// <param name="Data">データ</param>
		public void AddDataToColumn(int ColumnIndex, object Data)
		{
			Columns[CurrentSheetIndex][ColumnIndex].DataList.Add(Data);
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
		/// 複数シートを使用するようにする。
		/// <param name="InSheetCount">シート数</param>
		/// </summary>
		public void SetMultipleSheet(int InSheetCount)
		{
			IsMultipleSheet = true;
			SheetCount = InSheetCount;
			for (int i = 1; i < SheetCount; i++)
			{
				Columns.Add(new List<Column>());
			}
		}

		/// <summary>
		/// 複数シートの整合性チェック
		/// </summary>
		/// <returns>問題なければtrueを返す</returns>
		public bool CheckMultipleSheetIntegrity()
		{
			if (!IsMultipleSheet) { return true; }

			for (int i = 1; i < SheetCount; i++)
			{
				if(Columns[0].Count != Columns[i].Count) { return false; }
				for(int j = 0;j < Columns[0].Count; j++)
				{
					if(Columns[0][j] != Columns[i][j]) { return false; }
				}
			}

			return true;
		}

		/// <summary>
		/// オートキーの生成.
		/// </summary>
		public void GenerateAutoKey()
		{
			if (!IsAutoKey) { return; }
			
			for(int i = 0; i< SheetCount; i++)
			{
				int Index = 1;
				if (Columns[i].Count == 1) { Index = 0; }
				Column AutoKeyColumn = new Column("AutoKey", Type.s32);
				for (int j = 0; j < Columns[i][Index].DataList.Count; j++)
				{
					AutoKeyColumn.DataList.Add((double)(j + 1));
				}
				Columns[i].Insert(0, AutoKeyColumn);
			}
		}
		
	}
}
