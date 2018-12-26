﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace DLCGenerator
{

	/// <summary>
	/// DLC生成クラス
	/// </summary>
	public class DLCGenerator : AutomationToolProcess
	{

		/// <summary>
		/// DLC名.
		/// </summary>
		private string DLCName;

		/// <summary>
		/// ターゲットプラットフォーム
		/// </summary>
		private EPlatformTarget TargetPlatform;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InAutomationToolPath">AutomationToolのパス</param>
		/// <param name="InDLCName">DLC名</param>
		/// <param name="InTargetPlatform">ターゲットプラットフォーム</param>
		public DLCGenerator(string InAutomationToolPath, string InDLCName, EPlatformTarget InTargetPlatform)
			: base(InAutomationToolPath)
		{
			DLCName = InDLCName;
			TargetPlatform = InTargetPlatform;
		}

		/// <summary>
		/// 実行.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Execute()
		{
			string Argument = "-ScriptsForProject=" + ProjectPath + " ";
			Argument += "BuildCookRun -project=" + ProjectPath + " ";
			Argument += "-noP4 ";
			Argument += "-clientconfig=Development ";
			Argument += "-serverconfig=Development ";
			Argument += "-nocompileeditor ";
			Argument += "-installed ";
			Argument += "-ue4exe=UE4Editor-Cmd.exe ";
			Argument += "-utf8output ";
			string Target = "Win64";
			switch (TargetPlatform)
			{
				case EPlatformTarget.Windows:

					Target = "Win64";
					break;

				case EPlatformTarget.Android:

					Target = "Android";
					break;

				case EPlatformTarget.iOS:

					Target = "iOS";
					break;
			}

			Argument += "-platform=" + Target + " ";
			Argument += "-targetplatform=" + Target + " ";
			Argument += "-build ";
			Argument += "-cook ";
			Argument += "-map= ";
			Argument += "-unversionedcookedcontent ";
			Argument += "-pak ";
			Argument += "-dlcname=" + DLCName + " ";
			Argument += "-DLCIncludeEngineContent ";
			Argument += "-basedonreleaseversion=1.0 ";
			Argument += "-compressed ";
			Argument += "-stage ";
			Argument += "-package ";
			Argument += "-archive ";
			Argument += "-archivedirectory=" + Config.GetDLCDirectory() + " ";
			Argument += "-cmdline=\"-Messaging\"";

			Process AutomationToolProcess = CreateProcess(Argument);

			AutomationToolProcess.OutputDataReceived += (sender, e) =>
			{
				Console.WriteLine(e.Data);
			};

			AutomationToolProcess.ErrorDataReceived += (sender, e) =>
			{
				Console.WriteLine(e.Data);
			};

			AutomationToolProcess.Start();
			AutomationToolProcess.BeginOutputReadLine();
			AutomationToolProcess.BeginErrorReadLine();
			AutomationToolProcess.WaitForExit();
			int ExitCode = AutomationToolProcess.ExitCode;
			AutomationToolProcess.CancelOutputRead();
			AutomationToolProcess.CancelErrorRead();
			AutomationToolProcess.Close();

			string SavedDir = Path.GetDirectoryName(ProjectPath) + "\\Plugins\\" + DLCName + "\\Saved";
			Directory.Delete(SavedDir, true);

			return (ExitCode == 0);
		}

	}
}
