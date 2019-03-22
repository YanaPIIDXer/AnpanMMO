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
	print("ＤＢパスワード：<input type=text name=\"DBPassword\"><br />\n");
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
		
		// @TODO:ログインチェック。
		
		session_start();
		$_SESSION['DBUserName'] = htmlspecialchars($_POST['DBUserName']);
		$_SESSION['DBPassword'] = htmlspecialchars($_POST['DBPassword']);
		
		// 元いたページにリダイレクト
		header('Location: ' . $_GET['from']);
	}
?>
</body>
</html>