namespace HeightMapGenerator
{
	partial class WriteProgressForm
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
			this.WriteProgressBar = new System.Windows.Forms.ProgressBar();
			this.SuspendLayout();
			// 
			// WriteProgressBar
			// 
			this.WriteProgressBar.Location = new System.Drawing.Point(39, 57);
			this.WriteProgressBar.Name = "WriteProgressBar";
			this.WriteProgressBar.Size = new System.Drawing.Size(333, 23);
			this.WriteProgressBar.TabIndex = 1;
			// 
			// WriteProgressForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(417, 124);
			this.Controls.Add(this.WriteProgressBar);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "WriteProgressForm";
			this.Text = "書き込み中";
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.ProgressBar WriteProgressBar;
	}
}