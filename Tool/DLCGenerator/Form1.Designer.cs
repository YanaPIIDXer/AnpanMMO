namespace DLCGenerator
{
	partial class Form1
	{
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージ リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
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
			this.label1 = new System.Windows.Forms.Label();
			this.AutomationToolPathText = new System.Windows.Forms.Label();
			this.AutomationToolSelectButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 38);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(149, 15);
			this.label1.TabIndex = 0;
			this.label1.Text = "Automation Tool Path:";
			// 
			// AutomationToolPathText
			// 
			this.AutomationToolPathText.AutoSize = true;
			this.AutomationToolPathText.Location = new System.Drawing.Point(22, 66);
			this.AutomationToolPathText.Name = "AutomationToolPathText";
			this.AutomationToolPathText.Size = new System.Drawing.Size(0, 15);
			this.AutomationToolPathText.TabIndex = 1;
			// 
			// AutomationToolSelectButton
			// 
			this.AutomationToolSelectButton.Location = new System.Drawing.Point(167, 34);
			this.AutomationToolSelectButton.Name = "AutomationToolSelectButton";
			this.AutomationToolSelectButton.Size = new System.Drawing.Size(49, 23);
			this.AutomationToolSelectButton.TabIndex = 2;
			this.AutomationToolSelectButton.Text = "...";
			this.AutomationToolSelectButton.UseVisualStyleBackColor = true;
			this.AutomationToolSelectButton.Click += new System.EventHandler(this.AutomationToolSelectButton_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(865, 308);
			this.Controls.Add(this.AutomationToolSelectButton);
			this.Controls.Add(this.AutomationToolPathText);
			this.Controls.Add(this.label1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label AutomationToolPathText;
		private System.Windows.Forms.Button AutomationToolSelectButton;
	}
}

