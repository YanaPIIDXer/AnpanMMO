namespace MasterConverter
{
	partial class AddTransportTargetWindow
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
			this.NameTextBox = new System.Windows.Forms.TextBox();
			this.UserNameTextBox = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.PasswordTextBox = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.BinaryPathTextBox = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.OKButton = new System.Windows.Forms.Button();
			this.CancelButton = new System.Windows.Forms.Button();
			this.HostTextBox = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(36, 24);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(37, 15);
			this.label1.TabIndex = 0;
			this.label1.Text = "名称";
			// 
			// NameTextBox
			// 
			this.NameTextBox.Location = new System.Drawing.Point(155, 24);
			this.NameTextBox.Name = "NameTextBox";
			this.NameTextBox.Size = new System.Drawing.Size(255, 22);
			this.NameTextBox.TabIndex = 1;
			// 
			// UserNameTextBox
			// 
			this.UserNameTextBox.Location = new System.Drawing.Point(155, 108);
			this.UserNameTextBox.Name = "UserNameTextBox";
			this.UserNameTextBox.Size = new System.Drawing.Size(255, 22);
			this.UserNameTextBox.TabIndex = 3;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(36, 108);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(58, 15);
			this.label2.TabIndex = 2;
			this.label2.Text = "ユーザ名";
			// 
			// PasswordTextBox
			// 
			this.PasswordTextBox.Location = new System.Drawing.Point(155, 160);
			this.PasswordTextBox.Name = "PasswordTextBox";
			this.PasswordTextBox.Size = new System.Drawing.Size(255, 22);
			this.PasswordTextBox.TabIndex = 4;
			this.PasswordTextBox.UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(36, 160);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(64, 15);
			this.label3.TabIndex = 4;
			this.label3.Text = "パスワード";
			// 
			// BinaryPathTextBox
			// 
			this.BinaryPathTextBox.Location = new System.Drawing.Point(155, 205);
			this.BinaryPathTextBox.Name = "BinaryPathTextBox";
			this.BinaryPathTextBox.Size = new System.Drawing.Size(255, 22);
			this.BinaryPathTextBox.TabIndex = 5;
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(19, 208);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(120, 15);
			this.label4.TabIndex = 6;
			this.label4.Text = "バイナリ転送先パス";
			// 
			// OKButton
			// 
			this.OKButton.Location = new System.Drawing.Point(77, 255);
			this.OKButton.Name = "OKButton";
			this.OKButton.Size = new System.Drawing.Size(111, 55);
			this.OKButton.TabIndex = 8;
			this.OKButton.Text = "OK";
			this.OKButton.UseVisualStyleBackColor = true;
			this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
			// 
			// CancelButton
			// 
			this.CancelButton.Location = new System.Drawing.Point(241, 255);
			this.CancelButton.Name = "CancelButton";
			this.CancelButton.Size = new System.Drawing.Size(111, 55);
			this.CancelButton.TabIndex = 9;
			this.CancelButton.Text = "キャンセル";
			this.CancelButton.UseVisualStyleBackColor = true;
			this.CancelButton.Click += new System.EventHandler(this.CancelButton_Click);
			// 
			// HostTextBox
			// 
			this.HostTextBox.Location = new System.Drawing.Point(155, 64);
			this.HostTextBox.Name = "HostTextBox";
			this.HostTextBox.Size = new System.Drawing.Size(255, 22);
			this.HostTextBox.TabIndex = 2;
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(36, 64);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(41, 15);
			this.label5.TabIndex = 10;
			this.label5.Text = "ホスト";
			// 
			// AddTransportTargetWindow
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(435, 339);
			this.Controls.Add(this.HostTextBox);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.CancelButton);
			this.Controls.Add(this.OKButton);
			this.Controls.Add(this.BinaryPathTextBox);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.PasswordTextBox);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.UserNameTextBox);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.NameTextBox);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
			this.Name = "AddTransportTargetWindow";
			this.Text = "AddTransportTargetWindow";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox NameTextBox;
		private System.Windows.Forms.TextBox UserNameTextBox;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox PasswordTextBox;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox BinaryPathTextBox;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Button OKButton;
		private System.Windows.Forms.Button CancelButton;
		private System.Windows.Forms.TextBox HostTextBox;
		private System.Windows.Forms.Label label5;
	}
}