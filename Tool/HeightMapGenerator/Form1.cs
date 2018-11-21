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
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;

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

		// ハイトマップ出力ボタンが押された。
		private void OutputHeightMapButton_Click(object sender, EventArgs e)
		{
			if(ObjListBox.SelectedIndex == -1)
			{
				MessageBox.Show("ハイトマップを出力するobjファイルを選択してください。");
				return;
			}

			string ObjName = ObjListBox.SelectedItem.ToString();
			string FilePath = Config.ObjFilesDirectory + "\\" + ObjName + ".obj";
			HeightMapGenerator HeightMapGen = new HeightMapGenerator(FilePath);
			if(!HeightMapGen.Generate())
			{
				MessageBox.Show(ObjName + "のハイトマップ生成に失敗しました。");
				return;
			}

			MessageBox.Show(ObjName + "のハイトマップを生成しました。");
		}

		// ModelViewerが読み込まれた。
		private void ModelViewer_Load(object sender, EventArgs e)
		{
			GL.ClearColor(Color4.Black);
			GL.Enable(EnableCap.DepthTest);
		}

		// ModelViewerのリサイズ
		private void ModelViewer_Resize(object sender, EventArgs e)
		{
			GL.Viewport(0, 0, ModelViewer.Size.Width, ModelViewer.Size.Height);
			GL.MatrixMode(MatrixMode.Projection);
			Matrix4 Proj = Matrix4.CreatePerspectiveFieldOfView((float)Math.PI / 4, (float)ModelViewer.Size.Width / (float)ModelViewer.Size.Height, 1.0f, 64.0f);
			GL.LoadMatrix(ref Proj);
		}

		// ModelViewerの再描画.
		private void ModelViewer_Paint(object sender, PaintEventArgs e)
		{
			GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

			GL.MatrixMode(MatrixMode.Modelview);
			Matrix4 modelview = Matrix4.LookAt(Vector3.Zero, Vector3.UnitZ, Vector3.UnitY);
			GL.LoadMatrix(ref modelview);

			GL.Begin(PrimitiveType.Quads);
			
			GL.Color4(Color4.White);
			
			GL.End();
			ModelViewer.SwapBuffers();
		}
	}
}
