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
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(379, 431);
			this.Controls.Add(this.ObjListBox);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ListBox ObjListBox;
	}
}

