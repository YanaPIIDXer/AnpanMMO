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
	public class ServerSorceGenerator
	{

		/// <summary>
		/// ヘッダファイルテンプレートパス
		/// </summary>
		private static readonly string HeaderTemplatePath = "SourceTemplate\\Server\\Template.h";

		/// <summary>
		/// ソースファイルテンプレートパス
		/// </summary>
		private static readonly string SourceTemplatePath = "SourceTemplate\\Server\\Template.cpp";

		/// <summary>
		/// 出力先ディレクトリ
		/// </summary>
		private string TargetDirectory;

		/// <summary>
		/// マスタ名.
		/// </summary>
		private string MasterName;

		/// <summary>
		/// カラムデータ
		/// </summary>
		private List<Column> ColumnList;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InTargetDirectory">出力先ディレクトリ</param>
		/// <param name="InMasterName">マスタ名</param>
		/// <param name="InColumnList">カラムリスト</param>
		public ServerSorceGenerator(string InTargetDirectory, string InMasterName, List<Column> InColumnList)
		{
			TargetDirectory = InTargetDirectory;
			MasterName = InMasterName;
			ColumnList = InColumnList;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			//try
			{
				string Dir = Path.GetDirectoryName(TargetDirectory);
				if(!Directory.Exists(Dir))
				{
					Directory.CreateDirectory(Dir);
				}

				GenerateHeader();
				GenerateSource();
			}
			//catch
			//{
			//	return false;
			//}

			return true;
		}

		/// <summary>
		/// ヘッダ生成.
		/// </summary>
		private void GenerateHeader()
		{
			string Source = "";
			using (StreamReader Reader = new StreamReader(HeaderTemplatePath, Encoding.UTF8))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			string FilePath = TargetDirectory + "\\" + MasterName + ".h";
			if(!Directory.Exists(TargetDirectory))
			{
				Directory.CreateDirectory(TargetDirectory);
			}
			using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.UTF8))
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
			using (StreamReader Reader = new StreamReader(SourceTemplatePath, Encoding.UTF8))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			using (StreamWriter Writer = new StreamWriter(TargetDirectory + "\\" + MasterName + ".cpp", false, Encoding.UTF8))
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
			// インクルードガード
			string IncludeGuard = "__" + MasterName.ToUpper() + "_H__";
			Source = Source.Replace("$INCLUDE_GUARD$", IncludeGuard);

			// ヘッダファイル名.
			string HeaderFileName = MasterName + ".h";
			Source = Source.Replace("$HEADER_FILE_NAME$", HeaderFileName);

			// クラス名.
			string ClassName = GenerateClassName();
			Source = Source.Replace("$CLASS_NAME$", ClassName);

			// アイテム構造体名.
			string ItemStructName = MasterName + "Item";
			Source = Source.Replace("$ITEM_STRUCT_NAME$", ItemStructName);

			// キーの型名.
			string KeyType = Util.ToTypeNameString(ColumnList[0].DataType);
			Source = Source.Replace("$KEY_TYPE$", KeyType);

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
			Source = Source.Replace("$MASTER_NAME$", MasterName);

			// アイテムバインド
			string ItemBind = "";
			foreach(Column Col in ColumnList)
			{
				ItemBind += "\t";
				switch(Col.DataType)
				{
					case Type.Float:

						ItemBind += "Query.AddResultFloat(&BindItem." + Col.Name + ");";
						break;

					case Type.String:

						ItemBind += "Query.AddResultString(" + Col.Name + "Bind);";
						break;

					default:

						ItemBind += "Query.AddResultInt(&BindItem." + Col.Name + ");";
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
				StringBind += "char " + Col.Name + "Bind[128];";
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
			string AppendToMap = "Items[" + ColumnList[0].Name + "] = Item;";
			Source = Source.Replace("$APPEND_TO_MAP$", AppendToMap);

			return Source;
		}

		/// <summary>
		/// クラス名生成.
		/// </summary>
		/// <returns>クラス名</returns>
		private string GenerateClassName()
		{
			return MasterName + "Master";
		}

	}
}
