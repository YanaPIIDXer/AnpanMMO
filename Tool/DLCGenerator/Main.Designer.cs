namespace DLCGenerator
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
			this.label1 = new System.Windows.Forms.Label();
			this.AutomationToolPathText = new System.Windows.Forms.Label();
			this.AutomationToolSelectButton = new System.Windows.Forms.Button();
			this.ExecuteButton = new System.Windows.Forms.Button();
			this.DLCListBox = new System.Windows.Forms.CheckedListBox();
			this.TransportTargetList = new System.Windows.Forms.ListBox();
			this.AddTransportTargetButton = new System.Windows.Forms.Button();
			this.TransportButton = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.TargetPlatformComboBox = new System.Windows.Forms.ComboBox();
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
			// ExecuteButton
			// 
			this.ExecuteButton.Location = new System.Drawing.Point(299, 279);
			this.ExecuteButton.Name = "ExecuteButton";
			this.ExecuteButton.Size = new System.Drawing.Size(132, 43);
			this.ExecuteButton.TabIndex = 3;
			this.ExecuteButton.Text = "DLC作成";
			this.ExecuteButton.UseVisualStyleBackColor = true;
			this.ExecuteButton.Click += new System.EventHandler(this.ExecuteButton_Click);
			// 
			// DLCListBox
			// 
			this.DLCListBox.FormattingEnabled = true;
			this.DLCListBox.Location = new System.Drawing.Point(224, 100);
			this.DLCListBox.Name = "DLCListBox";
			this.DLCListBox.Size = new System.Drawing.Size(225, 157);
			this.DLCListBox.TabIndex = 4;
			// 
			// TransportTargetList
			// 
			this.TransportTargetList.FormattingEnabled = true;
			this.TransportTargetList.ItemHeight = 15;
			this.TransportTargetList.Location = new System.Drawing.Point(545, 100);
			this.TransportTargetList.Name = "TransportTargetList";
			this.TransportTargetList.Size = new System.Drawing.Size(232, 154);
			this.TransportTargetList.TabIndex = 5;
			// 
			// AddTransportTargetButton
			// 
			this.AddTransportTargetButton.Location = new System.Drawing.Point(569, 279);
			this.AddTransportTargetButton.Name = "AddTransportTargetButton";
			this.AddTransportTargetButton.Size = new System.Drawing.Size(118, 43);
			this.AddTransportTargetButton.TabIndex = 6;
			this.AddTransportTargetButton.Text = "転送先の追加";
			this.AddTransportTargetButton.UseVisualStyleBackColor = true;
			this.AddTransportTargetButton.Click += new System.EventHandler(this.AddTransportTargetButton_Click);
			// 
			// TransportButton
			// 
			this.TransportButton.Location = new System.Drawing.Point(735, 279);
			this.TransportButton.Name = "TransportButton";
			this.TransportButton.Size = new System.Drawing.Size(118, 43);
			this.TransportButton.TabIndex = 7;
			this.TransportButton.Text = "転送";
			this.TransportButton.UseVisualStyleBackColor = true;
			this.TransportButton.Click += new System.EventHandler(this.TransportButton_Click);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(22, 86);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(106, 15);
			this.label2.TabIndex = 8;
			this.label2.Text = "Target Platform";
			// 
			// TargetPlatformComboBox
			// 
			this.TargetPlatformComboBox.FormattingEnabled = true;
			this.TargetPlatformComboBox.Items.AddRange(new object[] {
            "Windows",
            "Android",
            "iOS"});
			this.TargetPlatformComboBox.Location = new System.Drawing.Point(25, 122);
			this.TargetPlatformComboBox.Name = "TargetPlatformComboBox";
			this.TargetPlatformComboBox.Size = new System.Drawing.Size(121, 23);
			this.TargetPlatformComboBox.TabIndex = 9;
			this.TargetPlatformComboBox.Text = "Windows";
			this.TargetPlatformComboBox.SelectedIndexChanged += new System.EventHandler(this.TargetPlatformComboBox_SelectedIndexChanged);
			// 
			// Main
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(865, 346);
			this.Controls.Add(this.TargetPlatformComboBox);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.TransportButton);
			this.Controls.Add(this.AddTransportTargetButton);
			this.Controls.Add(this.TransportTargetList);
			this.Controls.Add(this.DLCListBox);
			this.Controls.Add(this.ExecuteButton);
			this.Controls.Add(this.AutomationToolSelectButton);
			this.Controls.Add(this.AutomationToolPathText);
			this.Controls.Add(this.label1);
			this.Name = "Main";
			this.Text = "DLC生成ツール";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label AutomationToolPathText;
		private System.Windows.Forms.Button AutomationToolSelectButton;
		private System.Windows.Forms.Button ExecuteButton;
		private System.Windows.Forms.CheckedListBox DLCListBox;
		private System.Windows.Forms.ListBox TransportTargetList;
		private System.Windows.Forms.Button AddTransportTargetButton;
		private System.Windows.Forms.Button TransportButton;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.ComboBox TargetPlatformComboBox;
	}
}

