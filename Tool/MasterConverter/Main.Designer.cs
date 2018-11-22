namespace MasterConverter
{
	partial class Main
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
			this.AddTransportTargetButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// OutputButton
			// 
			this.OutputButton.Location = new System.Drawing.Point(75, 275);
			this.OutputButton.Name = "OutputButton";
			this.OutputButton.Size = new System.Drawing.Size(127, 45);
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
			// AddTransportTargetButton
			// 
			this.AddTransportTargetButton.Location = new System.Drawing.Point(75, 195);
			this.AddTransportTargetButton.Name = "AddTransportTargetButton";
			this.AddTransportTargetButton.Size = new System.Drawing.Size(127, 45);
			this.AddTransportTargetButton.TabIndex = 2;
			this.AddTransportTargetButton.Text = "転送対象の追加";
			this.AddTransportTargetButton.UseVisualStyleBackColor = true;
			this.AddTransportTargetButton.Click += new System.EventHandler(this.AddTransportTargetButton_Click);
			// 
			// Main
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(282, 347);
			this.Controls.Add(this.AddTransportTargetButton);
			this.Controls.Add(this.TransportTargetList);
			this.Controls.Add(this.OutputButton);
			this.Name = "Main";
			this.Text = "マスタ生成ツール";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button OutputButton;
		private System.Windows.Forms.ListBox TransportTargetList;
		private System.Windows.Forms.Button AddTransportTargetButton;
	}
}

