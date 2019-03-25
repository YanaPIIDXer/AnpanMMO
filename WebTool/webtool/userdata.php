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
	$Stmt = $Conn->query("select CustomerId, Name, Level, Exp, RightEquip, LeftEquip, IsGM from CharacterData;");
	print("<table border=1>\n");
	print("<caption>ユーザデータ</caption>\n");
	print("<tr style=\"background:#FF00CC\">\n");
	print("<th>ＩＤ</th>\n");
	print("<th>キャラクタ名</th>\n");
	print("<th>レベル</th>\n");
	print("<th>経験値</th>\n");
	print("<th>ＧＭフラグ</th>\n");
	print("</tr>\n");
	while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
	{
		print("<tr>\n");
		print("<th>" . $Row['CustomerId'] . "</th>\n");
		print("<th>" . $Row['Name'] . "</th>\n");
		print("<th>" . $Row['Level'] . "</th>\n");
		print("<th>" . $Row['Exp'] . "</th>\n");
		$GMFlag = "";
		if($Row['IsGM'] == '1')
		{
			$GMFlag = "○";
		}
		print("<th>" . $GMFlag . "</th>\n");
		print("</tr>\n");
	}
	print("</table><br />\n");
?>
</body>
</html>
