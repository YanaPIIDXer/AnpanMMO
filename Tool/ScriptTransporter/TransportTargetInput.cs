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
	public partial class TransportTargetInput : Form
	{
		public TransportTargetInput()
		{
			InitializeComponent();
		}

		private void OKButton_Click(object sender, EventArgs e)
		{
			if(NameTextBox.Text == "")
			{
				MessageBox.Show("名称を入力してください。");
				return;
			}

			if(HostTextBox.Text == "")
			{
				MessageBox.Show("ホストを入力してください。");
				return;
			}

			if(UserNameTextBox.Text == "")
			{
				MessageBox.Show("ユーザ名を入力してください。");
				return;
			}

			if(PasswordTextBox.Text == "")
			{
				MessageBox.Show("パスワードを入力してください。");
				return;
			}

			if(ClientDirectoryTextBox.Text == "")
			{
				MessageBox.Show("クライアント転送先ディレクトリを入力してください。");
				return;
			}

			if(ServerDirectoryTextBox.Text == "")
			{
				MessageBox.Show("サーバ転送先ディレクトリを入力してください、");
				return;
			}

			if(!Directory.Exists(Config.TransportSettingFileDirectory))
			{
				Directory.CreateDirectory(Config.TransportSettingFileDirectory);
			}

			using (StreamWriter Writer = new StreamWriter(Config.TransportSettingFileDirectory + "\\" + NameTextBox.Text + ".dat"))
			{
				Writer.WriteLine(HostTextBox.Text);
				Writer.WriteLine(UserNameTextBox.Text);
				Writer.WriteLine(PasswordTextBox.Text);
				Writer.WriteLine(ClientDirectoryTextBox.Text);
				Writer.WriteLine(ServerDirectoryTextBox.Text);
			}

			MessageBox.Show("追加しました。");

			DialogResult = DialogResult.OK;
			Close();
		}

		// キャンセルボタンが押された。
		private void CancelButton_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.Cancel;
			Close();
		}
		
	}
}
