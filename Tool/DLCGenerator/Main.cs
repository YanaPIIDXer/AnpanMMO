﻿using System;
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
	public partial class Main : Form
	{

		/// <summary>
		/// AutomationToolのパスを記述するiniファイルのファイル名.
		/// </summary>
		private static readonly string AutomationToolDirIniFileName = "AutomationToolPath.ini";

		/// <summary>
		/// AutomationToolのパス
		/// </summary>
		private string AutomationToolPath = "";

		/// <summary>
		/// ターゲットプラットフォーム
		/// </summary>
		private EPlatformTarget TargetPlatform = EPlatformTarget.Windows;

		public Main()
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
			ReleaseGenerator ReleaseGen = new ReleaseGenerator(AutomationToolPath, TargetPlatform);
			if(!ReleaseGen.Execute())
			{
				MessageBox.Show("リリースの生成に失敗しました。");
				return;
			}

			Console.WriteLine("リリースを生成しました。\n\n");
			
			var DLCList = DLCListBox.CheckedItems;
			foreach(var DLC in DLCList)
			{
				string DLCName = DLC.ToString();
				DLCGenerator DLCGen = new DLCGenerator(AutomationToolPath, DLCName, TargetPlatform);
				if(!DLCGen.Execute())
				{
					MessageBox.Show(DLCName + "のＤＬＣ生成に失敗しました。");
					return;
				}
				Console.WriteLine(DLCName + "のＤＬＣを生成しました。\n\n");
			}
			
			MessageBox.Show("完了しました。");
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
			if(TransportTargetList.SelectedIndex == -1)
			{
				MessageBox.Show("転送先を選択してください。");
				return;
			}

			string Host = "";
			string UserName = "";
			string Password = "";
			string TargetDirectory = "";
			try
			{
				string TargetFilePath = Config.TransportTargetsPath + "\\" + TransportTargetList.SelectedItem.ToString() + ".dat";
				using (StreamReader Reader = new StreamReader(TargetFilePath))
				{
					Host = Reader.ReadLine();
					UserName = Reader.ReadLine();
					Password = Reader.ReadLine();
					TargetDirectory = Reader.ReadLine();
				}
			}
			catch
			{
				MessageBox.Show("転送先の読み込みに失敗しました。");
				return;
			}

			string DLCPath = Config.PakPath;
			switch (TargetPlatform)
			{
				case EPlatformTarget.Windows:

					DLCPath += "\\Windows";
					TargetDirectory += "/windows";
					break;

				case EPlatformTarget.Android:

					DLCPath += "\\Android";
					TargetDirectory += "/android";
					break;

				case EPlatformTarget.iOS:

					DLCPath += "\\iOS";
					TargetDirectory += "/ios";
					break;
			}

			VersionGenerator VersionGen = new VersionGenerator(DLCPath, Directory.GetFiles(DLCPath, "*.pak"));
			if (!VersionGen.Generate())
			{
				MessageBox.Show("バージョンファイルの生成に失敗しました。");
				return;
			}

			Console.WriteLine("バージョンファイルを生成しました。");

			if(!Directory.Exists(DLCPath))
			{
				MessageBox.Show("DLCが生成されていません。");
				return;
			}

			string[] Files = Directory.GetFiles(DLCPath);
			foreach(var FilePath in Files)
			{
				string FileName = Path.GetFileName(FilePath);
				Console.Write(FileName + "の転送中...");
				FileTransporter Transporter = new FileTransporter(FilePath, Host, UserName, Password, TargetDirectory);
				if(!Transporter.Transport())
				{
					Console.WriteLine("失敗。");
					MessageBox.Show(FileName + "の転送に失敗しました。");
					return;
				}

				Console.WriteLine("成功。");
			}

			Console.WriteLine("転送完了。");
			MessageBox.Show("DLCの転送が完了しました。");
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

		// ターゲットプラットフォームのコンボボックスのアイテムが選択された。
		private void TargetPlatformComboBox_SelectedIndexChanged(object sender, EventArgs e)
		{
			TargetPlatform = (EPlatformTarget)TargetPlatformComboBox.SelectedIndex;
		}
	}
}
