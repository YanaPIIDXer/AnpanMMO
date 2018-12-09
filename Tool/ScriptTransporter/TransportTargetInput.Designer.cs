namespace ScriptTransporter
{
	partial class TransportTargetInput
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.label1 = new System.Windows.Forms.Label();
			this.UserNameTextBox = new System.Windows.Forms.TextBox();
			this.PasswordTextBox = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.HostTextBox = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.ClientDirectoryTextBox = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.ServerDirectoryTextBox = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.OKButton = new System.Windows.Forms.Button();
			this.CancelButton = new System.Windows.Forms.Button();
			this.NameTextBox = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(92, 117);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(58, 15);
			this.label1.TabIndex = 0;
			this.label1.Text = "ユーザ名";
			// 
			// UserNameTextBox
			// 
			this.UserNameTextBox.Location = new System.Drawing.Point(218, 114);
			this.UserNameTextBox.Name = "UserNameTextBox";
			this.UserNameTextBox.Size = new System.Drawing.Size(232, 22);
			this.UserNameTextBox.TabIndex = 3;
			// 
			// PasswordTextBox
			// 
			this.PasswordTextBox.Location = new System.Drawing.Point(218, 172);
			this.PasswordTextBox.Name = "PasswordTextBox";
			this.PasswordTextBox.Size = new System.Drawing.Size(232, 22);
			this.PasswordTextBox.TabIndex = 4;
			this.PasswordTextBox.UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(92, 175);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(64, 15);
			this.label2.TabIndex = 2;
			this.label2.Text = "パスワード";
			// 
			// HostTextBox
			// 
			this.HostTextBox.Location = new System.Drawing.Point(218, 57);
			this.HostTextBox.Name = "HostTextBox";
			this.HostTextBox.Size = new System.Drawing.Size(232, 22);
			this.HostTextBox.TabIndex = 2;
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(92, 60);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(41, 15);
			this.label3.TabIndex = 4;
			this.label3.Text = "ホスト";
			// 
			// ClientDirectoryTextBox
			// 
			this.ClientDirectoryTextBox.Location = new System.Drawing.Point(218, 227);
			this.ClientDirectoryTextBox.Name = "ClientDirectoryTextBox";
			this.ClientDirectoryTextBox.Size = new System.Drawing.Size(232, 22);
			this.ClientDirectoryTextBox.TabIndex = 5;
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(35, 230);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(177, 15);
			this.label4.TabIndex = 5;
			this.label4.Text = "クライアント転送先ディレクトリ";
			// 
			// ServerDirectoryTextBox
			// 
			this.ServerDirectoryTextBox.Location = new System.Drawing.Point(218, 283);
			this.ServerDirectoryTextBox.Name = "ServerDirectoryTextBox";
			this.ServerDirectoryTextBox.Size = new System.Drawing.Size(232, 22);
			this.ServerDirectoryTextBox.TabIndex = 6;
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(47, 286);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(150, 15);
			this.label5.TabIndex = 7;
			this.label5.Text = "サーバ転送先ディレクトリ";
			// 
			// OKButton
			// 
			this.OKButton.Location = new System.Drawing.Point(56, 337);
			this.OKButton.Name = "OKButton";
			this.OKButton.Size = new System.Drawing.Size(155, 64);
			this.OKButton.TabIndex = 9;
			this.OKButton.Text = "OK";
			this.OKButton.UseVisualStyleBackColor = true;
			this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
			// 
			// CancelButton
			// 
			this.CancelButton.Location = new System.Drawing.Point(294, 337);
			this.CancelButton.Name = "CancelButton";
			this.CancelButton.Size = new System.Drawing.Size(155, 64);
			this.CancelButton.TabIndex = 10;
			this.CancelButton.Text = "キャンセル";
			this.CancelButton.UseVisualStyleBackColor = true;
			this.CancelButton.Click += new System.EventHandler(this.CancelButton_Click);
			// 
			// NameTextBox
			// 
			this.NameTextBox.Location = new System.Drawing.Point(217, 12);
			this.NameTextBox.Name = "NameTextBox";
			this.NameTextBox.Size = new System.Drawing.Size(232, 22);
			this.NameTextBox.TabIndex = 1;
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(91, 15);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(37, 15);
			this.label6.TabIndex = 12;
			this.label6.Text = "名称";
			// 
			// TransportTargetInput
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(526, 450);
			this.Controls.Add(this.NameTextBox);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.CancelButton);
			this.Controls.Add(this.OKButton);
			this.Controls.Add(this.ServerDirectoryTextBox);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.ClientDirectoryTextBox);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.HostTextBox);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.PasswordTextBox);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.UserNameTextBox);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Name = "TransportTargetInput";
			this.Text = "転送先の入力";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox UserNameTextBox;
		private System.Windows.Forms.TextBox PasswordTextBox;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox HostTextBox;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox ClientDirectoryTextBox;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox ServerDirectoryTextBox;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Button OKButton;
		private System.Windows.Forms.Button CancelButton;
		private System.Windows.Forms.TextBox NameTextBox;
		private System.Windows.Forms.Label label6;
	}
}