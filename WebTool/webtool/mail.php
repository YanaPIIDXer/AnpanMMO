<?php
	require_once('funcs\\session.php');
	session_start();
	if(RedirectIfNotLogIn('index.php')){ return; }
?>
<html>
<head>
<title>メール送信ページ</title>
</head>
<body>
<h1>メール送信</h1>
<hr />
<form method="POST" action="mailsend.php" onsubmit="return confirm('送信しますか？')">
	<?php
		if(!isset($_POST['CustomerId']))
		{
			print("エラー<br />\n");
			print("<a href=\"index.php\">トップページへ</a><br />\n");
			return;
		}
		
		print("<input type=\"hidden\" name=\"CustomerId\" value=" . $_POST['CustomerId'] . ">\n");
	?>
	タイトル：<input type="text" name="Subject"><br />
	本文：<br />
	<textarea name="Body" cols="50" rows="10"></textarea><br />
	添付物タイプ：<br />
	<input type="radio" name="AttachmentType" Value=0 checked>無し<br />
	<input type="radio" name="AttachmentType" Value=1>アイテム<br />
	<input type="radio" name="AttachmentType" Value=2>ゴールド<br />
	アイテム（添付物タイプが「アイテム」の場合のみ有効）：
	<select name="AttachmentId">
	<?php
		require_once('funcs\\database.php');
		$Conn = MasterConnectionWithSession();
		if(!$Conn)
		{
			print("<option value=-1>エラー</option>\n");
			return;
		}
		
		// 消費アイテム
		$Stmt = $Conn->query("select Id, Name from Item;");
		while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
		{
			print("<option value=" . $Row['Id'] . ">" . $Row['Name'] . "</option>\n");
		}
		
		// 装備品.
		$Stmt = $Conn->query("select Id, Name from Equip;");
		while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
		{
			print("<option value=" . $Row['Id'] . ">" . $Row['Name'] . "</option>\n");
		}
	?>
	</select><br />
	数量：<input type="number" name="AttachmentCount"><br />
	<input type="submit" name="SendMail" value="送信"><br />
</form>
</body>
</html>
