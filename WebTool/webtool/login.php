<html>
<head>
<title>ログイン</title>
</head>
<body>
<h1>ログインページ</h1>
<hr />
<?php
	// ログインフォーム
	print("<form method=\"POST\" action=\"login.php?from=" . $_GET['from'] . "\">\n");
	print("ＤＢユーザ名：<input type=text name=\"DBUserName\"><br />\n");
	print("ＤＢパスワード：<input type=password name=\"DBPassword\"><br />\n");
	print("マスタユーザ名：<input type=text name=\"MasterUserName\"><br />\n");
	print("マスタパスワード：<input type=password name=\"MasterPassword\"><br />\n");
	print("<input type=submit name=\"LogIn\" value=ログイン><br />\n");
	print("</form>");

	// ログイン
	if(isset($_POST['LogIn']))
	{
		if(!isset($_POST['DBUserName']) || $_POST['DBUserName'] == "")
		{
			print("ＤＢユーザ名を入力してください。<br />\n");
			return;
		}
		
		if(!isset($_POST['DBPassword']) || $_POST['DBPassword'] == "")
		{
			print("ＤＢパスワードを入力してください。<br />\n");
			return;
		}
		
		if(!isset($_POST['MasterUserName']) || $_POST['MasterUserName'] == "")
		{
			print("マスタユーザ名を入力してください。<br />\n");
			return;
		}
		
		if(!isset($_POST['MasterPassword']) || $_POST['MasterPassword'] == "")
		{
			print("マスタパスワードを入力してください。<br />\n");
			return;
		}
		
		$DBUserName = htmlspecialchars($_POST['DBUserName']);
		$DBPassword = htmlspecialchars($_POST['DBPassword']);
		
		$MasterUserName = htmlspecialchars($_POST['MasterUserName']);
		$MasterPassword = htmlspecialchars($_POST['MasterPassword']);
		
		require_once('funcs\\database.php');
		$Conn = DBConnection($DBUserName, $DBPassword);
		if(!$Conn)
		{
			print("ログインに失敗しました。<br />\n");
			return;
		}
		
		$Conn = MasterConnection($MasterUserName, $MasterPassword);
		if(!$Conn)
		{
			print("ログインに失敗しました。<br />\n");
			return;
		}
		
		session_start();
		$_SESSION['DBUserName'] = $DBUserName;
		$_SESSION['DBPassword'] = $DBPassword;
		
		$_SESSION['MasterUserName'] = $MasterUserName;
		$_SESSION['MasterPassword'] = $MasterPassword;
		
		// 元いたページにリダイレクト
		header('Location: ' . $_GET['from']);
	}
?>
</body>
</html>
