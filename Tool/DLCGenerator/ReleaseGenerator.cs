using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Windows.Forms;

namespace DLCGenerator
{

	/// <summary>
	/// リリースを生成するクラス
	/// </summary>
	public class ReleaseGenerator : AutomationToolProcess
	{

		/// <summary>
		/// ターゲットプラットフォーム
		/// </summary>
		private EPlatformTarget TargetPlatform;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InAutomationToolPath">AutomationToolのパス</param>
		/// <param name="InTargetPlatform">ターゲットプラットフォーム</param>
		public ReleaseGenerator(string InAutomationToolPath, EPlatformTarget InTargetPlatform)
			: base(InAutomationToolPath)
		{
			TargetPlatform = InTargetPlatform;
		}

		/// <summary>
		/// 実行.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
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
			switch(TargetPlatform)
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
			Argument += "-createreleaseversion=1.0 ";
			Argument += "-compressed ";
			Argument += "-stage ";
			Argument += "-package ";
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

			return (ExitCode == 0);
		}

	}
}
