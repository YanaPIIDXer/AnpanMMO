using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace DLCGenerator
{

	/// <summary>
	/// リリースを生成するクラス
	/// </summary>
	public class ReleaseGenerator : AutomationToolProcess
	{

		/// <summary>
		/// プロジェクトのパス
		/// </summary>
		private string ProjectPath;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InAutomationToolPath">AutomationToolのパス</param>
		public ReleaseGenerator(string InAutomationToolPath)
			: base(InAutomationToolPath)
		{
			ProjectPath = Config.GetProjectFilePath();
		}

		/// <summary>
		/// 実行.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Execute()
		{
			string Argument = "-ScriptForProject=" + ProjectPath + " ";
			Argument += "BuildCookRun -project=" + ProjectPath + " ";
			Argument += "-noP4 ";
			Argument += "-clientconfig=Development ";
			Argument += "-serverconfig=Development ";
			Argument += "-nocompileeditor ";
			Argument += "-installed ";
			Argument += "-ue4exe=UE4Editor-Cmd.exe ";
			Argument += "-utf8output ";
			Argument += "-platform=Win64 ";
			Argument += "-targetplatform=Win64 ";
			Argument += "-build ";
			Argument += "-cook ";
			Argument += "-map= ";
			Argument += "-unversionedcookedcontent ";
			Argument += "-pak ";
			Argument += "-createreleaseversion=1.0 ";
			Argument += "-compressed";

			Process AutomationToolProcess = CreateProcess(Argument);
			AutomationToolProcess.Start();
			AutomationToolProcess.WaitForExit();
			string Error = AutomationToolProcess.StandardError.ReadToEnd();
			AutomationToolProcess.Close();

			return (Error == "");
		}

	}
}
