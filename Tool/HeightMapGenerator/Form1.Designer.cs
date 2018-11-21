namespace HeightMapGenerator
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
			this.ObjListBox = new System.Windows.Forms.ListBox();
			this.OutputHeightMapButton = new System.Windows.Forms.Button();
			this.ModelViewer = new OpenTK.GLControl();
			this.SuspendLayout();
			// 
			// ObjListBox
			// 
			this.ObjListBox.FormattingEnabled = true;
			this.ObjListBox.ItemHeight = 15;
			this.ObjListBox.Location = new System.Drawing.Point(39, 41);
			this.ObjListBox.Name = "ObjListBox";
			this.ObjListBox.Size = new System.Drawing.Size(288, 289);
			this.ObjListBox.TabIndex = 0;
			// 
			// OutputHeightMapButton
			// 
			this.OutputHeightMapButton.Location = new System.Drawing.Point(194, 365);
			this.OutputHeightMapButton.Name = "OutputHeightMapButton";
			this.OutputHeightMapButton.Size = new System.Drawing.Size(133, 54);
			this.OutputHeightMapButton.TabIndex = 1;
			this.OutputHeightMapButton.Text = "ハイトマップ出力";
			this.OutputHeightMapButton.UseVisualStyleBackColor = true;
			this.OutputHeightMapButton.Click += new System.EventHandler(this.OutputHeightMapButton_Click);
			// 
			// ModelViewer
			// 
			this.ModelViewer.BackColor = System.Drawing.Color.Black;
			this.ModelViewer.Location = new System.Drawing.Point(367, 41);
			this.ModelViewer.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.ModelViewer.Name = "ModelViewer";
			this.ModelViewer.Size = new System.Drawing.Size(327, 289);
			this.ModelViewer.TabIndex = 2;
			this.ModelViewer.VSync = false;
			this.ModelViewer.Load += new System.EventHandler(this.ModelViewer_Load);
			this.ModelViewer.Paint += new System.Windows.Forms.PaintEventHandler(this.ModelViewer_Paint);
			this.ModelViewer.Resize += new System.EventHandler(this.ModelViewer_Resize);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(738, 431);
			this.Controls.Add(this.ModelViewer);
			this.Controls.Add(this.OutputHeightMapButton);
			this.Controls.Add(this.ObjListBox);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ListBox ObjListBox;
		private System.Windows.Forms.Button OutputHeightMapButton;
		private OpenTK.GLControl ModelViewer;
	}
}

