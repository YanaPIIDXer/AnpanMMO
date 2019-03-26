<?php
	require_once('funcs\\session.php');
	session_start();
	if(RedirectIfNotLogIn('userdata.php')){ return; }
?>

<html>
<head>
<title>ユーザデータ</title>
</head>
<body>
<h1>ユーザデータ</h1><hr />
<script>
	// ＢＡＮ確認ダイアログ表示.
	function CheckBan()
	{
		return confirm("ＢＡＮしますか？");
	}
	
	// ＢＡＮ解除確認ダイアログ表示.
	function CheckUnBan()
	{
		return confirm("ＢＡＮを解除しますか？");
	}
</script>

<?php
	require_once("funcs\\database.php");
	
	$Conn = DBConnectionWithSession();
	if(!$Conn)
	{
		print("DB Connection Error<br />\n");
		return;
	}
	
	// ユーザデータテーブルの構築.
	$Stmt = $Conn->query("select Id, UserCode, IsBunned from UserData;");
	print("<table border=1>\n");
	print("<caption>ユーザデータ</caption>\n");
	print("<tr style=\"background:#FF00CC\">\n");
	print("<th>ＩＤ</th>\n");
	print("<th>ユーザコード</th>\n");
	print("</tr>\n");
	while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
	{
		if($Row['IsBunned'] == 0)
		{
			print("<tr>\n");
		}
		else
		{
			print("<tr bgcolor=\"#FF0000\">\n");
		}
		print("<th>" . $Row['Id'] . "</th>\n");
		print("<th>" . $Row['UserCode'] . "</th>\n");

		// キャラクタページへのリンクを構築.
		print("<th>\n");
		print("<form method=\"POST\" name=\"form" . $Row['Id'] . "\" action=\"characterdata.php\">\n");
		print("	<input type=\"hidden\" name=\"CustomerId\" value=" . $Row['Id'] . ">\n");
		print("	<a href=\"characterdata.php\" onclick=\"document.form" . $Row['Id'] . ".submit();return false;\">キャラクタデータ閲覧</a>\n");
		print("</form>\n");
		print("</th>\n");
		
		// ＢＡＮ
		print("<th>\n");
		if($Row['IsBunned'] == 0)
		{
			// ＢＡＮ
			print("<form method=\"POST\" action=\"\" onsubmit=\"return CheckBan()\">\n");
			print("	<input type=\"hidden\" name=\"CustomerId\" value=" . $Row['Id'] . ">\n");
			print("	<input type=\"submit\" name=\"Ban\" value=\"ＢＡＮ\">\n");
			print("</form>\n");
		}
		else
		{
			// ＢＡＮ解除.
			print("<form method=\"POST\" action=\"\" onsubmit=\"return CheckUnBan()\">\n");
			print("	<input type=\"hidden\" name=\"CustomerId\" value=" . $Row['Id'] . ">\n");
			print("	<input type=\"submit\" name=\"UnBan\" value=\"ＢＡＮ解除\">\n");
			print("</form>\n");
		}
		
		print("</th>\n");
		print("</tr>\n");
	}
	print("</table><br />\n");
?>

<?php
	$CustomerId = -1;
	if(isset($_POST['CustomerId']))
	{
		$CustomerId = $_POST['CustomerId'];
	}
	
	require_once('funcs\\util.php');
	require_once('funcs\\database.php');
	if(isset($_POST['Ban']))
	{
		// ＢＡＮ処理.
		$Conn = DBConnectionWithSession();
		if(!$Conn)
		{
			ShowAlert("ＤＢ接続エラー");
			return;
		}
		$Stmt = $Conn->prepare("update UserData set IsBunned=1 where Id = :CustomerId;");
		$Stmt->bindValue(':CustomerId', $CustomerId, PDO::PARAM_INT);
		if(!$Stmt->execute())
		{
			ShowAlert("ＳＱＬ実行エラー");
			return;
		}
		
		header("Location: userdata.php");
	}
	else if(isset($_POST['UnBan']))
	{
		// ＢＡＮ解除処理.
		$Conn = DBConnectionWithSession();
		if(!$Conn)
		{
			ShowAlert("ＤＢ接続エラー");
			return;
		}
		$Stmt = $Conn->prepare("update UserData set IsBunned=0 where Id = :CustomerId;");
		$Stmt->bindValue(':CustomerId', $CustomerId, PDO::PARAM_INT);
		if(!$Stmt->execute())
		{
			ShowAlert("ＳＱＬ実行エラー");
			return;
		}
		
		header("Location: userdata.php");
	}
?>

</body>
</html>
