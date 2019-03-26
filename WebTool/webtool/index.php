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
</body>
</html>
