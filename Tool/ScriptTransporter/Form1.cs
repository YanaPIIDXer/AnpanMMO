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
