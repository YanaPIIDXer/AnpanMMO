using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MasterConverter
{
	public partial class AddTransportTargetWindow : Form
	{
		public AddTransportTargetWindow()
		{
			InitializeComponent();
		}

		// OKボタンが押された。
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

			if(BinaryHostTextBox.Text == "")
			{
				MessageBox.Show("バイナリ転送先ホストを入力してください。");
				return;
			}

			if(BinaryPathTextBox.Text == "")
			{
				MessageBox.Show("バイナリ転送先パスを入力してください。");
				return;
			}

			TransportTargetWriter Writer = new TransportTargetWriter(NameTextBox.Text, HostTextBox.Text, UserNameTextBox.Text, PasswordTextBox.Text, BinaryHostTextBox.Text, BinaryPathTextBox.Text);
			if(!Writer.Write())
			{
				MessageBox.Show("転送先データの追加に失敗しました。");
				return;
			}

			MessageBox.Show("転送先データを追加しました。");

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
