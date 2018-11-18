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
				File.Copy(DLC, Config.PakPath + "\\" + DLCName + ".pak");
			}
		}
		
	}
}
