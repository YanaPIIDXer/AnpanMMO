using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace MasterConverter
{
	/// <summary>
	/// サーバ側ソースコード生成.
	/// </summary>
	public class ServerSourceGenerator
	{

		/// <summary>
		/// テンプレートパス
		/// </summary>
		private static readonly string TemplatePath = "SourceTemplate\\Server\\";

		/// <summary>
		/// ヘッダファイルテンプレートパス
		/// </summary>
		private static readonly string HeaderTemplatePath = TemplatePath + "Template.h";

		/// <summary>
		/// ソースファイルテンプレートパス
		/// </summary>
		private static readonly string SourceTemplatePath = TemplatePath + "Template.cpp";

		/// <summary>
		/// 出力先ディレクトリ
		/// </summary>
		private string TargetDirectory;
		
		/// <summary>
		/// マスタデータ
		/// </summary>
		private MasterData Master;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InTargetDirectory">出力先ディレクトリ</param>
		/// <param name="InMaster">マスタデータ</param>
		public ServerSourceGenerator(string InTargetDirectory, MasterData InMaster)
		{
			TargetDirectory = InTargetDirectory;
			Master = InMaster;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			try
			{
				string Dir = Path.GetDirectoryName(TargetDirectory);
				if(!Directory.Exists(Dir))
				{
					Directory.CreateDirectory(Dir);
				}

				GenerateHeader();
				GenerateSource();
			}
			catch
			{
				return false;
			}

			return true;
		}

		/// <summary>
		/// ヘッダ生成.
		/// </summary>
		private void GenerateHeader()
		{
			string Source = "";
			using (StreamReader Reader = new StreamReader(HeaderTemplatePath, Encoding.GetEncoding("Shift-JIS")))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			string FilePath = TargetDirectory + "\\" + Master.Name + "Master.h";
			if(!Directory.Exists(TargetDirectory))
			{
				Directory.CreateDirectory(TargetDirectory);
			}

			string LoadedSrc = "";
			if(File.Exists(FilePath))
			{
				using(StreamReader Reader = new StreamReader(FilePath, Encoding.GetEncoding("Shift-JIS")))
				{
					LoadedSrc = Reader.ReadToEnd();
				}
			}

			if(LoadedSrc == Source) { return; }

			using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.GetEncoding("Shift-JIS")))
			{
				Writer.Write(Source);
			}
		}

		/// <summary>
		/// ソース生成.
		/// </summary>
		private void GenerateSource()
		{
			string Source = "";
			using (StreamReader Reader = new StreamReader(SourceTemplatePath, Encoding.GetEncoding("Shift-JIS")))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			string FilePath = TargetDirectory + "\\" + Master.Name + "Master.cpp";

			string LoadedSrc = "";
			if (File.Exists(FilePath))
			{
				using (StreamReader Reader = new StreamReader(FilePath, Encoding.GetEncoding("Shift-JIS")))
				{
					LoadedSrc = Reader.ReadToEnd();
				}
			}

			// 更新不要.
			if (LoadedSrc == Source) { return; }

			using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.GetEncoding("Shift-JIS")))
			{
				Writer.Write(Source);
			}
		}

		/// <summary>
		/// タグの変換.
		/// </summary>
		/// <param name="Source">変換前のソース</param>
		/// <returns>変換後のソース</returns>
		private string ReplaceTags(string Source)
		{
			var ColumnList = Master.GetColumns(0);

			// 取得関数宣言.
			string GetItemFunctionDecrare = "const $ITEM_STRUCT_NAME$ *GetItem($KEY_TYPE$ Key) const;";
			if(Master.IsAutoKey)
			{
				if(ColumnList.Count <= 2)
				{
					GetItemFunctionDecrare = "";
				}
				else
				{
					GetItemFunctionDecrare = "std::vector<const $ITEM_STRUCT_NAME$ *> CollectItems($KEY_TYPE$ Key) const;";
				}
			}
			Source = Source.Replace("$GET_ITEN_FUNCTION_DECRARE$", GetItemFunctionDecrare);

			// キー取得関数.
			string KeyFunctionFileName = TemplatePath + "GetKeyFunction.txt";
			if(Master.IsAutoKey)
			{
				KeyFunctionFileName = TemplatePath + "CollectItemFunction.txt";
			}
			string KeyFunction = "";
			if(!Master.IsAutoKey || (Master.IsAutoKey && ColumnList.Count > 2))
			{
				using (StreamReader Reader = new StreamReader(KeyFunctionFileName, Encoding.GetEncoding("shift-jis")))
				{
					KeyFunction = Reader.ReadToEnd();
				}
			}
			Source = Source.Replace("$GET_KEY_FUNCTION$", KeyFunction);

			// インクルードガード
			string IncludeGuard = "__" + Master.Name.ToUpper() + "MASTER_H__";
			Source = Source.Replace("$INCLUDE_GUARD$", IncludeGuard);

			// ヘッダファイル名.
			string HeaderFileName = Master.Name + "Master.h";
			Source = Source.Replace("$HEADER_FILE_NAME$", HeaderFileName);

			// クラス名.
			string ClassName = GenerateClassName();
			Source = Source.Replace("$CLASS_NAME$", ClassName);

			// アイテム構造体名.
			string ItemStructName = Master.Name + "Item";
			Source = Source.Replace("$ITEM_STRUCT_NAME$", ItemStructName);

			// キーの型名.
			string KeyType = Util.ToTypeNameString(ColumnList[0].DataType);
			if(Master.IsAutoKey && ColumnList.Count > 2)
			{
				KeyType = Util.ToTypeNameString(ColumnList[1].DataType);
			}
			Source = Source.Replace("$KEY_TYPE$", KeyType);

			// キーの名前
			string KeyName = ColumnList[0].Name;
			if(Master.IsAutoKey)
			{
				KeyName = ColumnList[1].Name;
			}
			Source = Source.Replace("$KEY_NAME$", KeyName);

			// Enum
			string EnumList = "";
			foreach(var Enum in Master.EnumList)
			{
				EnumList += "\tenum\n\t{";
				foreach (var Data in Enum.EnumList)
				{
					EnumList += "\n\t\t" + Data.Key + " = " + Data.Value + ",";
				}
				EnumList += "\n\t};\n";
			}
			Source = Source.Replace("$ENUMS$", EnumList);

			// アイテムリスト
			string ItemList = "";
			foreach (Column Col in ColumnList)
			{
				string Item = "\t" + Util.ToTypeNameString(Col.DataType);
				Item += " " + Col.Name + ";";
				ItemList += Item + "\n";
			}
			Source = Source.Replace("$ITEM_LIST$", ItemList);

			// マスタ名.
			Source = Source.Replace("$MASTER_NAME$", Master.Name);

			// アイテムバインド
			string ItemBind = "";
			foreach(Column Col in ColumnList)
			{
				ItemBind += "\t";
				switch(Col.DataType)
				{
					case Type.Float:

						ItemBind += "Query.BindResultFloat(&BindItem." + Col.Name + ");";
						break;

					case Type.String:

						ItemBind += "Query.BindResultString(" + Col.Name + "Bind);";
						break;
						
					case Type.s32:
					case Type.u32:

						ItemBind += "Query.BindResultInt(&BindItem." + Col.Name + ");";
						break;

					case Type.s16:
					case Type.u16:

						ItemBind += "Query.BIndResultShort(&BindItem." + Col.Name + ");";
						break;

					case Type.s8:
					case Type.u8:

						ItemBind += "Query.BindResultChar(&BindItem." + Col.Name + ");";
						break;

				}
				ItemBind += "\n";
			}
			Source = Source.Replace("$ITEM_BIND$", ItemBind);

			// 文字列バインド
			string StringBind = "";
			foreach(Column Col in ColumnList)
			{
				if(Col.DataType != Type.String) { continue; }
				StringBind += "\t";
				if(Col.DataType == Type.String)
				{
					StringBind += "char ";
				}
				else
				{
					StringBind += "wchar_t ";
				}
				StringBind += Col.Name + "Bind[128];";
			}
			Source = Source.Replace("$STRING_BIND$", StringBind);

			// アイテムフェッチ
			string ItemFetch = "";
			foreach(Column Col in ColumnList)
			{
				ItemFetch += "\t\t";
				if(Col.DataType == Type.String)
				{
					// stringの場合は別領域に格納されたものを放り込む。
					ItemFetch += "Item." + Col.Name + " = " + Col.Name + "Bind;";
				}
				else
				{
					ItemFetch += "Item." + Col.Name + " = BindItem." + Col.Name + ";";
				}
				ItemFetch += "\n";
			}
			Source = Source.Replace("$ITEM_FETCH$", ItemFetch);

			// マップへの追加.
			string AppendToMap = "Items[Item." + ColumnList[0].Name + "] = Item;";
			Source = Source.Replace("$APPEND_TO_MAP$", AppendToMap);

			return Source;
		}

		/// <summary>
		/// クラス名生成.
		/// </summary>
		/// <returns>クラス名</returns>
		private string GenerateClassName()
		{
			return Master.Name + "Master";
		}

	}
}
