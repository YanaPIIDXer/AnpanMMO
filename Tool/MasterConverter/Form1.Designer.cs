namespace MasterConverter
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
			this.OutputButton = new System.Windows.Forms.Button();
			this.TransportTargetList = new System.Windows.Forms.ListBox();
			this.SuspendLayout();
			// 
			// OutputButton
			// 
			this.OutputButton.Location = new System.Drawing.Point(83, 198);
			this.OutputButton.Name = "OutputButton";
			this.OutputButton.Size = new System.Drawing.Size(115, 45);
			this.OutputButton.TabIndex = 0;
			this.OutputButton.Text = "出力";
			this.OutputButton.UseVisualStyleBackColor = true;
			this.OutputButton.Click += new System.EventHandler(this.OutputButton_Click);
			// 
			// TransportTargetList
			// 
			this.TransportTargetList.FormattingEnabled = true;
			this.TransportTargetList.ItemHeight = 15;
			this.TransportTargetList.Location = new System.Drawing.Point(36, 12);
			this.TransportTargetList.Name = "TransportTargetList";
			this.TransportTargetList.Size = new System.Drawing.Size(207, 154);
			this.TransportTargetList.TabIndex = 1;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(282, 255);
			this.Controls.Add(this.TransportTargetList);
			this.Controls.Add(this.OutputButton);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button OutputButton;
		private System.Windows.Forms.ListBox TransportTargetList;
	}
}

