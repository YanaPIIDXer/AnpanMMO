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
		print("<tr>\n");
		print("<th>" . $Row['Id'] . "</th>\n");
		print("<th>" . $Row['UserCode'] . "</th>\n");

		// キャラクタページへのリンクを構築.
		print("<th>\n");
		print("<form method=\"POST\" name=\"form" . $Row['Id'] . "\" action=\"characterdata.php\">\n");
		print("	<input type=\"hidden\" name=\"CustomerId\" value=" . $Row['Id'] . ">\n");
		print("	<a href=\"characterdata.php\" onclick=\"document.form" . $Row['Id'] . ".submit();return false;\">キャラクタデータ閲覧</a>\n");
		print("</form>\n");
		
		print("</th>\n");
		print("</tr>\n");
	}
	print("</table><br />\n");
?>
</body>
</html>
