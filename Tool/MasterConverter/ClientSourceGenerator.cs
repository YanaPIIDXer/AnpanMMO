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
		/// ヘッダファイルテンプレートパス
		/// </summary>
		private static readonly string HeaderTemplatePath = "SourceTemplate\\Client\\Template.h";

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
		public ClientSourceGenerator(string InTargetDirectory, string InMasterName, List<Column> InColumnList)
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
			try
			{
				string Dir = Path.GetDirectoryName(TargetDirectory);
				if (!Directory.Exists(Dir))
				{
					Directory.CreateDirectory(Dir);
				}

				GenerateHeader();
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

			string FilePath = TargetDirectory + "\\" + MasterName + "Master.h";
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
			string IncludeGuard = "__" + MasterName.ToUpper() + "MASTER_H__";
			Source = Source.Replace("$INCLUDE_GUARD$", IncludeGuard);
			
			// アイテム構造体名.
			string ItemStructName = MasterName + "Item";
			Source = Source.Replace("$ITEM_STRUCT_NAME$", ItemStructName);
			
			// アイテムリスト
			string ItemList = "";
			foreach (Column Col in ColumnList)
			{
				string Item = "\t" + Util.ToTypeNameString(Col.DataType);
				Item += " " + Col.Name + ";";
				ItemList += Item + "\n";
			}
			Source = Source.Replace("$ITEM_LIST$", ItemList);

			// シリアライズ
			string ItemSerialize = "";
			foreach(Column Col in ColumnList)
			{
				ItemSerialize += "\t\t";
				ItemSerialize += "pStream->Serialize(&" + Col.Name + ");";
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
			return MasterName + "Master";
		}

	}
}
