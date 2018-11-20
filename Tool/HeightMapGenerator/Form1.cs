using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace HeightMapGenerator
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
			ReloadObjListBox();
		}

		/// <summary>
		/// objリストボックスのリロード
		/// </summary>
		private void ReloadObjListBox()
		{
			ObjListBox.Items.Clear();
			string[] ObjFiles = Directory.GetFiles(Config.ObjFilesDirectory, "*.obj");
			foreach(var ObjFile in ObjFiles)
			{
				ObjListBox.Items.Add(Path.GetFileNameWithoutExtension(ObjFile));
			}
		}
		
	}
}
