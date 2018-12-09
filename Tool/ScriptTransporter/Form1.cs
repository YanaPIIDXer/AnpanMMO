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

namespace ScriptTransporter
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}

		// 転送先追加ボタンが押された。
		private void AddTargetButton_Click(object sender, EventArgs e)
		{
			TransportTargetInput Input = new TransportTargetInput();
			DialogResult Result = Input.ShowDialog();
			if(Result != DialogResult.OK) { return; }
			ReloadTransportTargets();
		}

		// 転送ボタンが押された。
		private void TransportButton_Click(object sender, EventArgs e)
		{
			if(TransportTargetListBox.SelectedIndex == -1)
			{
				MessageBox.Show("転送先を選択してください。");
				return;
			}

			string Host = "";
			string UserName = "";
			string Password = "";
			string ClientDir = "";
			string ServerDir = "";
			using (StreamReader Reader = new StreamReader(Config.TransportSettingFileDirectory + "\\" + TransportTargetListBox.SelectedItem + ".dat"))
			{
				Host = Reader.ReadLine();
				UserName = Reader.ReadLine();
				Password = Reader.ReadLine();
				ClientDir = Reader.ReadLine();
				ServerDir = Reader.ReadLine();
			}
			
			// 一時ディレクトリ作成.
			if(!Directory.Exists(Config.TemporaryDirectory))
			{
				Directory.CreateDirectory(Config.TemporaryDirectory);
			}

			// スクリプトディレクトリのスクリプトを全部一時ディレクトリにコピー
			string[] Scripts = Directory.GetFiles(Config.ScriptDirectory, "*.lua", SearchOption.TopDirectoryOnly);
			foreach(var Script in Scripts)
			{
				File.Copy(Script, Config.TemporaryDirectory + "\\" + Path.GetFileName(Script));
			}

			// まずはサーバ用ディレクトリに転送。
			Scripts = Directory.GetFiles(Config.TemporaryDirectory);
			foreach(var Script in Scripts)
			{
				Console.Write(Path.GetFileName(Script) + "の転送中...");
				FileTransporter Transporter = new FileTransporter(Script, Host, UserName, Password, ServerDir);
				if(!Transporter.Transport())
				{
					Console.WriteLine("失敗。");
					MessageBox.Show("転送に失敗しました。");
					DeleteTemporaryDirectory();
					return;
				}

				Console.WriteLine("成功。");
			}

			// クライアント用ディレクトリに転送。
			
			// まずは暗号化.
			foreach(var Script in Scripts)
			{
				string FileName = Path.GetFileName(Script);
				if(FileName == "Functions.lua" || FileName == "Flags.lua") { continue; }		// 暗号化しないもの。
				ScriptEncryption Encryption = new ScriptEncryption(Script);

				Console.Write(FileName + "の暗号化中...");
				if(!Encryption.Encryption())
				{
					Console.WriteLine("失敗。");
					MessageBox.Show("暗号化に失敗しました。");
					DeleteTemporaryDirectory();
					return;
				}
				Console.WriteLine("成功。");
			}

			// バージョンファイル生成.
			VersionGenerator VersionGen = new VersionGenerator(Scripts);
			if(!VersionGen.Generate())
			{
				MessageBox.Show("バージョンファイルの生成に失敗しました。");
				DeleteTemporaryDirectory();
				return;
			}

			// 転送.
			string[] FileList = Directory.GetFiles(Config.TemporaryDirectory);
			foreach (var FilePath in FileList)
			{
				Console.Write(Path.GetFileName(FilePath) + "の転送中...");
				FileTransporter Transporter = new FileTransporter(FilePath, Host, UserName, Password, ClientDir);
				if (!Transporter.Transport())
				{
					Console.WriteLine("失敗。");
					MessageBox.Show("転送に失敗しました。");
					DeleteTemporaryDirectory();
					return;
				}

				Console.WriteLine("成功。");
			}

			MessageBox.Show("転送が完了しました。");

			DeleteTemporaryDirectory();
		}

		/// <summary>
		/// 一時ディレクトリの削除.
		/// </summary>
		private void DeleteTemporaryDirectory()
		{
			Directory.Delete(Config.TemporaryDirectory, true);
		}

		/// <summary>
		/// 転送先のリロード
		/// </summary>
		private void ReloadTransportTargets()
		{
			TransportTargetListBox.Items.Clear();
			if (!Directory.Exists(Config.TransportSettingFileDirectory)) { return; }
			string[] Targets = Directory.GetFiles(Config.TransportSettingFileDirectory, "*.dat", SearchOption.TopDirectoryOnly);
			foreach(string FilePath in Targets)
			{
				TransportTargetListBox.Items.Add(Path.GetFileNameWithoutExtension(FilePath));
			}
		}

		// メインフォームがロードされた。
		private void MainForm_Load(object sender, EventArgs e)
		{
			ReloadTransportTargets();
		}
	}
}
