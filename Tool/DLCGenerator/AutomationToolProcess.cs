using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DLCGenerator
{

	/// <summary>
	/// AutomationToolを使用するプロセスを扱うクラス
	/// </summary>
	public abstract class AutomationToolProcess
	{

		/// <summary>
		/// AutomationToolのパス
		/// </summary>
		private string AutomationToolPath;
		
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InAutomationToolPath">AutomationToolのパス</param>
		public AutomationToolProcess(string InAutomationToolPath)
		{
			AutomationToolPath = InAutomationToolPath;
		}

		/// <summary>
		/// Processを生成.
		/// </summary>
		/// <param name="Argument">引数</param>
		/// <returns>Process</returns>
		protected Process CreateProcess(string Argument)
		{
			Process CmdProcess = new Process();

			CmdProcess.StartInfo.FileName = AutomationToolPath;

			CmdProcess.StartInfo.UseShellExecute = false;
			CmdProcess.StartInfo.RedirectStandardError = true;
			CmdProcess.StartInfo.RedirectStandardInput = true;
			CmdProcess.StartInfo.RedirectStandardOutput = true;
			CmdProcess.StartInfo.CreateNoWindow = true;

			CmdProcess.StartInfo.Arguments = Argument;

			return CmdProcess;
		}
	}
}
