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
	public partial class TransportTargetWindow : Form
	{
		public TransportTargetWindow()
		{
			InitializeComponent();
		}

		// OKボタンが押された。
		private void OKButton_Click(object sender, EventArgs e)
		{
			if (NameTextBox.Text == "")
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

			if(TargetDirectoryTextBox.Text == "")
			{
				MessageBox.Show("転送先ディレクトリを入力してください。");
				return;
			}

			if(!SaveTransportTarget())
			{
				MessageBox.Show("転送先の追加に失敗しました。");
				return;
			}

			MessageBox.Show("転送先を追加しました。");

			DialogResult = DialogResult.OK;
			Close();
		}
		
		// キャンセルボタンが押された。
		private void CancelButton_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.Cancel;
			Close();
		}

		/// <summary>
		/// 転送先を保存.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		private bool SaveTransportTarget()
		{
			try
			{
				if(!Directory.Exists(Config.TransportTargetsPath))
				{
					Directory.CreateDirectory(Config.TransportTargetsPath);
				}
				using(StreamWriter Writer = new StreamWriter(Config.TransportTargetsPath + "\\" + NameTextBox.Text + ".dat"))
				{
					Writer.WriteLine(HostTextBox.Text);
					Writer.WriteLine(UserNameTextBox.Text);
					Writer.WriteLine(PasswordTextBox.Text);
					Writer.WriteLine(TargetDirectoryTextBox.Text);
				}
			}
			catch
			{
				return false;
			}

			return true;
		}

	}
}
