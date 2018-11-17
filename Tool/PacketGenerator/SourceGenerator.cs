using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NativePacketGenerator
{
	/// <summary>
	/// ソース生成.
	/// </summary>
	public class SourceGenerator
	{
		
		/// <summary>
		/// クラスデータ
		/// </summary>
		private ClassData Class = null;

		/// <summary>
		/// テンプレートファイル名.
		/// </summary>
		private static readonly string TemplateFileName = "templates\\Template.h";

		/// <summary>
		/// コンストラクタテンプレート名.
		/// </summary>
		private static readonly string ConstructorTemplateFileName = "templates\\Constructor.h";

		/// <summary>
		/// 置換結果.
		/// </summary>
		private string Result = "";

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InClass">クラスデータ</param>
		/// <param name="InOutputPath">出力先</param>
		public SourceGenerator(ClassData InClass)
		{
			Class = InClass;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrue</returns>
		public bool Generate()
		{
			try
			{
				string Template = ReadFromFile(TemplateFileName);
				Result = ParseTag(Template);
			} catch(Exception e)
			{
				Console.WriteLine(e.Message);
				return false;
			}
			return true;
		}

		/// <summary>
		/// ファイルから読み込み
		/// </summary>
		/// <param name="FileName">ファイル名</param>
		/// <returns>読み込んだテキスト</returns>
		private string ReadFromFile(string FileName)
		{
			StreamReader Reader = new StreamReader(FileName);
			string Result = Reader.ReadToEnd();
			Reader.Close();
			return Result;
		}

		/// <summary>
		/// 書き出し
		/// </summary>
		/// <param name="TargetPath">パス</param>
		/// <returns>成功したらtrue</returns>
		public bool Write(string TargetPath)
		{
			var OutputPath = TargetPath + "\\" + Class.ClassName + ".h";
			try
			{
				StreamWriter Writer = new StreamWriter(OutputPath);
				Writer.Write(Result);
				Writer.Close();
			}
			catch(Exception e)
			{
				Console.Error.WriteLine(e.Message);
				return false;
			}
			return true;
		}

		/// <summary>
		/// タグ解析.
		/// </summary>
		/// <param name="Template">テンプレート</param>
		/// <returns>タグ解析結果</returns>
		private string ParseTag(string Template)
		{
			// コンストラクタ。
			// メンバが無ければ消滅する。
			string Constructor = "";
			if (Class.Members.Count > 0)
			{
				Constructor = ReadFromFile(ConstructorTemplateFileName);
			}
			Template = Template.Replace("$CONSTRUCTOR$", Constructor);

			// インクルードガード
			Template = Template.Replace("$INCLUDE_GUARD$", "__" + Class.ClassName.ToUpper() + "_H__");

			// 追加インクルード
			string Includes = "";
			foreach(var FileName in Class.Includes)
			{
				Includes += "#include \"" + FileName + "\"\n";
			}
			Template = Template.Replace("$INCLUDES$", Includes);

			// クラス名.
			Template = Template.Replace("$CLASS_NAME$", Class.ClassName);

			// 基底クラス名.
			string BaseClassName = "";
			if(!Class.IsPureClass)
			{
				BaseClassName = " : public " + Class.BaseClassName;
			}
			Template = Template.Replace("$BASE_CLASS_NAME$", BaseClassName);

			// パケットＩＤ
			// @HACK:PacketBase以外のものを継承してもコイツができてしまう。
			//		 殆ど無いケースだからあまり考える必要は無いか・・・？
			string FunctionStr = "";
			if(!Class.IsPureClass)
			{
				FunctionStr = "virtual PacketID GetPacketID() const { return " + Class.PacketID + "; }";
			}
			Template = Template.Replace("$GET_PACKET_ID_FUNCTION$", FunctionStr);

			// enum
			string Enums = "";
			foreach(var KeyValue in Class.EnumList)
			{
				Enums += "enum " + KeyValue.Key + "\n\t{\n";
				foreach(var Data in  Class.EnumList[KeyValue.Key])
				{
					Enums += "\t\t" + Data.Name;
					if(!string.IsNullOrEmpty(Data.Value))
					{
						Enums += " = " + Data.Value;
					}
					Enums += ",\n";
				}
				Enums += "\t};";
			}
			Template = Template.Replace("$ENUMS$", Enums);

			// メンバ変数.
			string Members = "";
			for(int i = 0; i < Class.Members.Count; i++)
			{
				var MemberData = Class.Members[i];
				Members += MemberData.TypeName + " " + MemberData.Name + ";\n\t";
			}
			Template = Template.Replace("$MEMBERS$", Members);

			// コンストラクタのメンバ
			string ConstructorMembers = "";
			if(Class.IsForCacheServer)
			{
				ConstructorMembers += "u32 InClientId";
				if(Class.Members.Count > 0)
				{
					ConstructorMembers += ", ";
				}
			}
			if (Class.Members.Count > 0)
			{
				for (int i = 0; i < Class.Members.Count - 1; i++)
				{
					var MemberData = Class.Members[i];
					ConstructorMembers += MemberData.TypeName + " In" + MemberData.Name + ", ";
				}
				ConstructorMembers += Class.Members.Last().TypeName + " In" + Class.Members.Last().Name;
			}
			Template = Template.Replace("$CONSTRUCTOR_MEMBERS$", ConstructorMembers);

			// メンバを押し込む
			string PutMembers = "";
			if(Class.IsForCacheServer)
			{
				PutMembers += "ClientId = InClientId;\n\t\t";
			}
			for (int i = 0; i < Class.Members.Count; i++)
			{
				PutMembers += Class.Members[i].Name + " = In" + Class.Members[i].Name + ";\n\t\t";
			}
			Template = Template.Replace("$PUT_MEMBERS$", PutMembers);

			string SerializeFunctions = "";
			if(Class.IsForCacheServer && Class.BaseClassName == "CachePacketBase")
			{
				SerializeFunctions += "CachePacketBase::Serialize(pStream);\n\t\t";
			}
			for(int i = 0; i < Class.Members.Count; i++)
			{
				var Member = Class.Members[i];
				if(Member.IsPrimitive)
				{
					SerializeFunctions += "pStream->Serialize(&" + Member.Name + ");\n\t\t";
				}
				else
				{
					// StreamInterfaceが対応していない型は必ずStreamInterface *を引数に取る
					// Serialize関数を定義すること。
					SerializeFunctions += Member.Name + ".Serialize(pStream);\n\t\t";
				}
			}
			Template = Template.Replace("$SERIALIZE_MEMBERS$", SerializeFunctions);

			return Template;
		}

	}
}
