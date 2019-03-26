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

</body>
</html>
