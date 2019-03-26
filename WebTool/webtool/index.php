<?php
	require_once('funcs\\session.php');
	session_start();
	if(RedirectIfNotLogIn('index.php')){ return; }
?>

<html>
<head>
<title>メインページ</title>
</head>
<body>
<h1>メインページ</h1>
<hr />
<a href="userdata.php">ユーザデータ</a><br />
<form method="POST" name="BroadcastMail" action="mail.php">
	<input type="hidden" name="CustomerId" Value=-1>
	<a href="mail.php" onclick="document.BroadcastMail.submit(); return false;">登録者全員にメール送信</a>
</form>
</body>
</html>
