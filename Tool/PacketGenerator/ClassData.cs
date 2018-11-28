using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NativePacketGenerator
{

	/// <summary>
	/// クラスメンバ情報.
	/// </summary>
	public struct ClassMemberData
	{
		/// <summary>
		/// 型名.
		/// </summary>
		public string TypeName;

		/// <summary>
		/// メンバ名.
		/// </summary>
		public string Name;

		/// <summary>
		/// 標準的な型か？
		/// ※シリアライズ関数がStreamInterfaceに用意されているか？
		/// </summary>
		public bool IsPrimitive
		{
			get
			{
				switch(TypeName)
				{
					case "u8":
					case "s8":
					case "u16":
					case "s16":
					case "u32":
					case "s32":
					case "u64":
					case "s64":
					case "std::string":
					case "float":
						return true;
				}
				return false;
			}
		}
	}

	/// <summary>
	/// enumのデータ
	/// </summary>
	public class EnumData
	{
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InName">名前</param>
		/// <param name="InValue">値</param>
		public EnumData(string InName, string InValue)
		{
			Name = InName;
			Value = InValue;
		}

		/// <summary>
		/// 名前,
		/// </summary>
		public string Name { get; private set; }

		/// <summary>
		/// 値.
		/// </summary>
		public string Value { get; private set; }
	}
	
	/// <summary>
	/// Excelのシートから解析したクラス情報.
	/// </summary>
	public class ClassData
	{
		/// <summary>
		/// クラス名.
		/// </summary>
		public string ClassName { get; private set; }

		/// <summary>
		/// 基底クラス名
		/// </summary>
		private string _BaseClassName;
		public string BaseClassName
		{
			get
			{
				return _BaseClassName;
			}
			set
			{
				_BaseClassName = value;
				if(IsProcessPacket)
				{
					AddInclude("ProcessPacketBase.h");
				}
			}
		}

		/// <summary>
		/// 追加インクルード
		/// </summary>
		public List<string> Includes { get { return _Includes; } }
		private List<string> _Includes = new List<string>();

		/// <summary>
		/// 純粋なクラスか？
		/// ※何も継承していないクラスか？
		/// </summary>
		public bool IsPureClass { get { return string.IsNullOrEmpty(BaseClassName); } }
		
		/// <summary>
		/// パケットＩＤ
		/// </summary>
		public string PacketID { get; set; }

		/// <summary>
		/// Enumリスト
		/// </summary>
		public Dictionary<string, List<EnumData>> EnumList { get { return _EnumList; } }
		private Dictionary<string, List<EnumData>> _EnumList = new Dictionary<string, List<EnumData>>();

		/// <summary>
		/// メンバ情報.
		/// </summary>
		public List<ClassMemberData> Members { get { return _Members; } }
		private List<ClassMemberData> _Members = new List<ClassMemberData>();

		/// <summary>
		/// キャッシュサーバ向けか？
		/// </summary>
		public bool IsForCacheServer { get; private set; }

		/// <summary>
		/// プロセスパケットか？
		/// </summary>
		public bool IsProcessPacket
		{
			get
			{
				return (BaseClassName == "ProcessPacketBase");
			}
		}

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InClassName">クラス名</param>
		public ClassData(string InClassName)
		{
			ClassName = InClassName;
			IsForCacheServer = false;
		}

		/// <summary>
		/// 追加インクルードするファイルを追加.
		/// </summary>
		/// <param name="FileName">ファイル名</param>
		public void AddInclude(string FileName)
		{
			Includes.Add(FileName);
		}

		/// <summary>
		/// メンバ追加.
		/// </summary>
		/// <param name="Data">メンバデータ</param>
		public void AddMember(ClassMemberData Data)
		{
			Members.Add(Data);
		}

		/// <summary>
		/// Enum追加.
		/// </summary>
		/// <param name="TypeName">Enumの型名</param>
		/// <param name="Name">要素名</param>
		/// <param name="Value">値</param>
		public void AddEnum(string TypeName, string Name, string Value)
		{
			if(!EnumList.ContainsKey(TypeName))
			{
				EnumList.Add(TypeName, new List<EnumData>());
			}
			EnumList[TypeName].Add(new EnumData(Name, Value));
		}

		/// <summary>
		/// キャッシュサーバ向けフラグを立てる。
		/// </summary>
		public void SetForCacheServerFlag()
		{
			IsForCacheServer = true;
		}

	}
}
