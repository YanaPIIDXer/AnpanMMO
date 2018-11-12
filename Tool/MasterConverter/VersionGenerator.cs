using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;

namespace MasterConverter
{

	/// <summary>
	/// バージョンファイル生成クラス
	/// </summary>
	public class VersionGenerator
	{

		/// <summary>
		/// ファイルリスト
		/// </summary>
		private string[] FileList;

		public VersionGenerator(string[] InFileList)
		{
			FileList = InFileList;
		}

		public bool Generate()
		{
			try
			{
				string FilePath = Config.TemporaryDirectoryPath + "\\" + "Version.csv";
				using (StreamWriter Writer = new StreamWriter(FilePath))
				{
					foreach(var TargetFilePath in FileList)
					{
						string FileName = Path.GetFileName(TargetFilePath);
						Writer.Write(FileName + ",");
						string Hash = GetHash(TargetFilePath);
						Writer.WriteLine(Hash);
					}
				}
			}
			catch
			{
				return false;
			}

			return true;
		}

		/// <summary>
		/// ハッシュ値を計算.
		/// </summary>
		/// <param name="FilePath">対象ファイル</param>
		/// <returns>ハッシュ値</returns>
		private string GetHash(string FilePath)
		{
			string Hash = "";
			FileStream ReadStream = new FileStream(FilePath, FileMode.Open);
			using (BinaryReader Reader = new BinaryReader(ReadStream))
			{
				char[] Chars = Reader.ReadChars((int)ReadStream.Length);
				byte[] Bytes = new byte[Chars.Length];
				for(int i = 0; i < Chars.Length; i++)
				{
					Bytes[i] = (byte)Chars[i];
				}
				MD5CryptoServiceProvider Md5 = new MD5CryptoServiceProvider();
				byte[] HashBytes = Md5.ComputeHash(Bytes);
				Md5.Clear();
				StringBuilder Builder = new StringBuilder();
				foreach(var b in HashBytes)
				{
					Builder.Append(b.ToString("x2"));
				}
				Hash = Builder.ToString();
			}

			return Hash;
		}

	}
}
