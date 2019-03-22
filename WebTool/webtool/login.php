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
	print("<input type=submit name=\"LogIn\" value=ログイン><br />\n");
	print("</form>");

	// ログイン
	if(isset($_POST['LogIn']))
	{
		if(!isset($_POST['DBUserName']) || $_POST['DBUserName'] == "")
		{
			print("ユーザ名を入力してください。<br />\n");
			return;
		}
		
		if(!isset($_POST['DBPassword']) || $_POST['DBPassword'] == "")
		{
			print("パスワードを入力してください。<br />\n");
			return;
		}
		
		$UserName = htmlspecialchars($_POST['DBUserName']);
		$Password = htmlspecialchars($_POST['DBPassword']);
		
		require_once('funcs\\database.php');
		$Conn = DBConnection($UserName, $Password);
		if(!$Conn)
		{
			print("ログインに失敗しました。<br />\n");
			return;
		}
		
		session_start();
		$_SESSION['DBUserName'] = $UserName;
		$_SESSION['DBPassword'] = $Password;
		
		// 元いたページにリダイレクト
		header('Location: ' . $_GET['from']);
	}
?>
</body>
</html>