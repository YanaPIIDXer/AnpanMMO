using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// クライアントソース生成クラス
	/// </summary>
	public class ClientSourceGenerator
	{

		/// <summary>
		/// テンプレートパス
		/// </summary>
		private static readonly string TemplatePath = "SourceTemplate\\Client\\";

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
		MasterData Master;
		
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InTargetDirectory">出力先ディレクトリ</param>
		/// <param name="InMaster">マスタデータ</param>
		public ClientSourceGenerator(string InTargetDirectory, MasterData InMaster)
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
				if (!Directory.Exists(Dir))
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
			using (StreamReader Reader = new StreamReader(HeaderTemplatePath, Encoding.GetEncoding("shift-jis")))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			string FilePath = TargetDirectory + "\\" + Master.Name + "Master.h";
			if (!Directory.Exists(TargetDirectory))
			{
				Directory.CreateDirectory(TargetDirectory);
			}
			using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.GetEncoding("shift-jis")))
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
			using (StreamReader Reader = new StreamReader(SourceTemplatePath, Encoding.GetEncoding("shift-jis")))
			{
				Source = Reader.ReadToEnd();
			}

			Source = ReplaceTags(Source);

			string FilePath = TargetDirectory + "\\" + Master.Name + "Master.cpp";
			if (!Directory.Exists(TargetDirectory))
			{
				Directory.CreateDirectory(TargetDirectory);
			}
			using (StreamWriter Writer = new StreamWriter(FilePath, false, Encoding.GetEncoding("shift-jis")))
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
			string IncludeGuard = "__" + Master.Name.ToUpper() + "MASTER_H__";
			Source = Source.Replace("$INCLUDE_GUARD$", IncludeGuard);

			// 取得関数定義.
			string GetItemFunctionDecrare = "const $ITEM_STRUCT_NAME$ *Get($KEY_TYPE$ Key) const;";
			if (Master.IsAutoKey)
			{
				GetItemFunctionDecrare = "TArray<const $ITEM_STRUCT_NAME$ *> CollectItems($SECONDARY_KEY_TYPE$ Key) const;";
			}
			Source = Source.Replace("$GET_ITEM_FUNCTION_DECRARE$", GetItemFunctionDecrare);

			// 取得関数.
			string KeyFunctionFileName = TemplatePath + "GetKeyFunction.txt";
			if (Master.IsAutoKey)
			{
				KeyFunctionFileName = TemplatePath + "CollectItemFunction.txt";
			}
			using (StreamReader Reader = new StreamReader(KeyFunctionFileName, Encoding.GetEncoding("shift-jis")))
			{
				string KeyFunction = Reader.ReadToEnd();
				Source = Source.Replace("$GET_ITEM_FUNCTION$", KeyFunction);
			}

			// ヘッダファイル名.
			string HeaderFileName = Master.Name + "Master.h";
			Source = Source.Replace("$HEADER_FILE_NAME$", HeaderFileName);

			// バイナリファイル名.
			string BinaryFileName = Master.Name + ".bin";
			Source = Source.Replace("$BINARY_FILE_NAME$", BinaryFileName);

			// クラス名.
			string ClassName = GenerateClassName();
			Source = Source.Replace("$CLASS_NAME$", ClassName);

			// アイテム構造体名.
			string ItemStructName = Master.Name + "Item";
			Source = Source.Replace("$ITEM_STRUCT_NAME$", ItemStructName);

			var ColumnList = Master.GetColumns();

			// キーの型名.
			string KeyType = Util.ToTypeNameString(ColumnList[0].DataType);
			Source = Source.Replace("$KEY_TYPE$", KeyType);

			// キーの名前
			string KeyName = ColumnList[0].Name;
			Source = Source.Replace("$KEY_NAME$", KeyName);

			// セカンダリキーの型名.
			string SecondaryKeyType = Util.ToTypeNameString(ColumnList[1].DataType);
			Source = Source.Replace("$SECONDARY_KEY_TYPE$", SecondaryKeyType);

			// セカンダリキーの名前.
			string SecondaryKeyName = ColumnList[1].Name;
			Source = Source.Replace("$SECONDARY_KEY_NAME$", SecondaryKeyName);

			// アイテムリスト
			string ItemList = "";
			foreach (Column Col in ColumnList)
			{
				string TypeName = Util.ToTypeNameString(Col.DataType);
				if (Col.DataType == Type.String)
				{
					TypeName = "FString";
				}
				string Item = "\t" + TypeName;
				Item += " " + Col.Name + ";";
				ItemList += Item + "\n";
			}
			Source = Source.Replace("$ITEM_LIST$", ItemList);

			// シリアライズ
			string ItemSerialize = "";
			foreach(Column Col in ColumnList)
			{
				ItemSerialize += "\t\t";
				if(Col.DataType == Type.String)
				{
					ItemSerialize += "std::string Str" + Col.Name + ";\n\t\t";
					ItemSerialize += "if(!pStream->Serialize(&Str" + Col.Name + ")) { return false; }\n\t\t";
					ItemSerialize += Col.Name + " = UTF8_TO_TCHAR(Str" + Col.Name + ".c_str());";
				}
				else
				{
					ItemSerialize += "if(!pStream->Serialize(&" + Col.Name + ")) { return false; }";
				}
				ItemSerialize += "\n";
			}
			Source = Source.Replace("$ITEM_SERIALIZE$", ItemSerialize);
			
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
