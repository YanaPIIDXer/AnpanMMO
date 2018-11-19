using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace DLCGenerator
{
	public partial class Form1 : Form
	{

		/// <summary>
		/// AutomationToolのパスを記述するiniファイルのファイル名.
		/// </summary>
		private static readonly string AutomationToolDirIniFileName = "AutomationToolPath.ini";

		/// <summary>
		/// AutomationToolのパス
		/// </summary>
		private string AutomationToolPath = "";

		public Form1()
		{
			InitializeComponent();
			try
			{
				using (StreamReader Reader = new StreamReader(AutomationToolDirIniFileName))
				{
					AutomationToolPath = Reader.ReadLine();
				}
			}
			catch { }

			AutomationToolPathText.Text = AutomationToolPath;
			CollectDLCs();
			ReloadTransportTargetList();
		}

		/// <summary>
		/// DLCを列挙.
		/// </summary>
		private void CollectDLCs()
		{
			DLCListBox.Items.Clear();
			//var DLCs = Directory.EnumerateFiles("..\\Client\\AnpanMMO\\Plugins", "*.uplugin", SearchOption.AllDirectories);
			var DLCs = Directory.EnumerateDirectories("..\\Client\\AnpanMMO\\Plugins");
			foreach(var DLCPath in DLCs)
			{
				DLCListBox.Items.Add(Path.GetFileNameWithoutExtension(DLCPath));
			}
		}

		// AutomationToolを探すボタンが押された。
		private void AutomationToolSelectButton_Click(object sender, EventArgs e)
		{
			OpenFileDialog FileDialog = new OpenFileDialog();
			var Result = FileDialog.ShowDialog();
			if(Result != DialogResult.OK) { return; }
			AutomationToolPathText.Text = FileDialog.FileName;
			AutomationToolPath = FileDialog.FileName;

			try
			{
				using (StreamWriter Writer = new StreamWriter(AutomationToolDirIniFileName, false))
				{
					Writer.WriteLine(FileDialog.FileName);
				}
			}
			catch { }
		}

		// 実行ボタンが押された
		private void ExecuteButton_Click(object sender, EventArgs e)
		{
			ReleaseGenerator ReleaseGen = new ReleaseGenerator(AutomationToolPath);
			if(!ReleaseGen.Execute())
			{
				MessageBox.Show("リリースの生成に失敗しました。");
				return;
			}

			Console.WriteLine("リリースを生成しました。\n\n");

			string DLCPath = Config.GetDLCDirectory();
			if(!Directory.Exists(DLCPath))
			{
				Directory.CreateDirectory(DLCPath);
			}

			var DLCList = DLCListBox.SelectedItems;
			foreach(var DLC in DLCList)
			{
				string DLCName = DLC.ToString();
				DLCGenerator DLCGen = new DLCGenerator(AutomationToolPath, DLCName);
				if(!DLCGen.Execute())
				{
					MessageBox.Show(DLCName + "のＤＬＣ生成に失敗しました。");
					return;
				}
				Console.WriteLine(DLCName + "のＤＬＣを生成しました。\n\n");
			}

			MoveDLCs();

			VersionGenerator VersionGen = new VersionGenerator(Directory.GetFiles(Config.PakPath));
			if(!VersionGen.Generate())
			{
				MessageBox.Show("バージョンファイルの生成に失敗しました。");
				return;
			}

			Console.WriteLine("バージョンファイルを生成しました。");

			MessageBox.Show("完了しました。");
		}

		/// <summary>
		/// DLCを移動.
		/// </summary>
		private void MoveDLCs()
		{
			if(!Directory.Exists(Config.PakPath))
			{
				Directory.CreateDirectory(Config.PakPath);
			}

			var DLCs = Directory.EnumerateFiles(Config.GetDLCDirectory(), "*.pak", SearchOption.AllDirectories);
			foreach(var DLC in DLCs)
			{
				int Index = DLC.IndexOf("Plugins\\");
				var DLCName = DLC.Replace(DLC.Substring(0, Index + "Plugins\\".Length), "");
				DLCName = DLCName.Substring(0, DLCName.IndexOf("\\"));
				string TargetPath = Config.PakPath + "\\" + DLCName + ".pak";
				if(File.Exists(TargetPath))
				{
					File.Delete(TargetPath);
				}
				File.Copy(DLC, TargetPath);
			}
		}

		// 転送先を追加ボタンが押された。
		private void AddTransportTargetButton_Click(object sender, EventArgs e)
		{
			TransportTargetWindow Window = new TransportTargetWindow();
			DialogResult Result = Window.ShowDialog();
			if(Result != DialogResult.OK) { return; }
			ReloadTransportTargetList();
		}

		// 転送ボタンが押された。
		private void TransportButton_Click(object sender, EventArgs e)
		{

		}

		/// <summary>
		/// 転送先リストの再読み込み
		/// </summary>
		private void ReloadTransportTargetList()
		{
			TransportTargetList.Items.Clear();
			if (!Directory.Exists(Config.TransportTargetsPath)) { return; }
			string[] Files = Directory.GetFiles(Config.TransportTargetsPath);
			foreach(var FileName in Files)
			{
				TransportTargetList.Items.Add(Path.GetFileNameWithoutExtension(FileName));
			}
		}

	}
}
