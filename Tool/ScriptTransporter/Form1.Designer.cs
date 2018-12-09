namespace ScriptTransporter
{
	partial class MainForm
	{
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows フォーム デザイナーで生成されたコード

		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		private void InitializeComponent()
		{
			this.TransportTargetListBox = new System.Windows.Forms.ListBox();
			this.AddTargetButton = new System.Windows.Forms.Button();
			this.TransportButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// TransportTargetListBox
			// 
			this.TransportTargetListBox.FormattingEnabled = true;
			this.TransportTargetListBox.ItemHeight = 15;
			this.TransportTargetListBox.Location = new System.Drawing.Point(64, 13);
			this.TransportTargetListBox.Name = "TransportTargetListBox";
			this.TransportTargetListBox.Size = new System.Drawing.Size(350, 304);
			this.TransportTargetListBox.TabIndex = 0;
			// 
			// AddTargetButton
			// 
			this.AddTargetButton.Location = new System.Drawing.Point(76, 367);
			this.AddTargetButton.Name = "AddTargetButton";
			this.AddTargetButton.Size = new System.Drawing.Size(152, 50);
			this.AddTargetButton.TabIndex = 1;
			this.AddTargetButton.Text = "転送先の追加";
			this.AddTargetButton.UseVisualStyleBackColor = true;
			this.AddTargetButton.Click += new System.EventHandler(this.AddTargetButton_Click);
			// 
			// TransportButton
			// 
			this.TransportButton.Location = new System.Drawing.Point(262, 367);
			this.TransportButton.Name = "TransportButton";
			this.TransportButton.Size = new System.Drawing.Size(152, 50);
			this.TransportButton.TabIndex = 2;
			this.TransportButton.Text = "転送";
			this.TransportButton.UseVisualStyleBackColor = true;
			this.TransportButton.Click += new System.EventHandler(this.TransportButton_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(493, 473);
			this.Controls.Add(this.TransportButton);
			this.Controls.Add(this.AddTargetButton);
			this.Controls.Add(this.TransportTargetListBox);
			this.Name = "MainForm";
			this.Text = "スクリプト転送ツール";
			this.Load += new System.EventHandler(this.MainForm_Load);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ListBox TransportTargetListBox;
		private System.Windows.Forms.Button AddTargetButton;
		private System.Windows.Forms.Button TransportButton;
	}
}

