<html>
<head>
<title>ログイン</title>
</head>
<body>
<h1>ログインページ</h1>
<hr />
<?php
	print('<form action=' . $_GET['from'] . ' method=\"POST\">');
	print('ＤＢユーザ名：<input type=text name=\"DBUserName\"><br />');
	print('ＤＢパスワード：<input type=text name=\"DBPassword\"><br />');
	print('<input type=submit value=ログイン>');
	print('</form>');
?>
</body>
</html>