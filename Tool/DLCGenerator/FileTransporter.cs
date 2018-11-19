using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Renci.SshNet;

namespace DLCGenerator
{

	/// <summary>
	/// ファイル転送クラス
	/// </summary>
	public class FileTransporter
	{
		
		/// <summary>
		/// ファイルパス
		/// </summary>
		private string FilePath;

		/// <summary>
		/// 転送対象ホスト.
		/// </summary>
		private string TransportTargetHost;

		/// <summary>
		/// ユーザ名.
		/// </summary>
		private string UserName;

		/// <summary>
		/// パスワード
		/// </summary>
		private string Password;

		/// <summary>
		/// 対象ディレクトリ
		/// </summary>
		private string TargetDirectory;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InFilePath">ファイルパス</param>
		/// <param name="InTransportTargetHost">転送対象ホスト</param>
		/// <param name="InUserName">ユーザ名</param>
		/// <param name="InPassword">パスワード</param>
		/// <param name="InTargetDirectory">対象ディレクトリ</param>
		public FileTransporter(string InFilePath, string InTransportTargetHost, string InUserName, string InPassword, string InTargetDirectory)
		{
			FilePath = InFilePath;
			TransportTargetHost = InTransportTargetHost;
			UserName = InUserName;
			Password = InPassword;
			TargetDirectory = InTargetDirectory;

		}

		/// <summary>
		/// 転送.
		/// </summary>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Transport()
		{
			try
			{
				var AuthMethod = new PasswordAuthenticationMethod(UserName, Password);
				var ConnInfo = new ConnectionInfo(TransportTargetHost, 22, UserName, AuthMethod);
				using (var Client = new SftpClient(ConnInfo))
				{
					Client.Connect();
					if(!Client.Exists(TargetDirectory))
					{
						Client.CreateDirectory(TargetDirectory);
					}
					Client.ChangeDirectory(TargetDirectory);
					using (var FileStream = File.OpenRead(FilePath))
					{
						Client.UploadFile(FileStream, Path.GetFileName(FilePath), true);
					}

					Client.Disconnect();
				}
			}
			catch (Exception e)
			{
				Console.WriteLine("");
				Console.WriteLine(e.Message);
				return false;
			}
			return true;
		}

	}
}
