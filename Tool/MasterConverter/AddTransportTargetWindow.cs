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

			if(BinaryPathTextBox.Text == "")
			{
				MessageBox.Show("バイナリ転送先パスを入力してください。");
				return;
			}

		}

		// キャンセルボタンが押された。
		private void CancelButton_Click(object sender, EventArgs e)
		{
			Close();
		}
	}
}
