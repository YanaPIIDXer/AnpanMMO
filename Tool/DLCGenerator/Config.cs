using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace DLCGenerator
{

	/// <summary>
	/// コンフィグ
	/// </summary>
	public class Config
	{

		/// <summary>
		/// プロジェクトファイルパス
		/// </summary>
		private static readonly string ProjectFilePath = "../Client/AnpanMMO/AnpanMMO.uproject";

		/// <summary>
		/// プロジェクトファイルパスを絶対パスで取得.
		/// </summary>
		/// <returns>プロジェクトファイルの絶対パス</returns>
		public static string GetProjectFilePath()
		{
			string ProjPath = Path.GetFullPath(ProjectFilePath);
			return ProjPath;
		}

		/// <summary>
		/// DLCをブチ込むパス
		/// </summary>
		private static readonly string DLCPath = "DLCs";

		/// <summary>
		/// DLCをブチ込むパスを絶対パスで取得.
		/// </summary>
		/// <returns>DLCをブチ込むパスの絶対パス</returns>
		public static string GetDLCDirectory()
		{
			string Dir = Path.GetFullPath(DLCPath);
			return Dir;
		}

		/// <summary>
		/// Pakファイルをブチ込むパス
		/// </summary>
		public static readonly string PakPath = "Paks";

		/// <summary>
		/// 転送先を保存するパス
		/// </summary>
		public static readonly string TransportTargetsPath = "TransportTargets";

	}
}
