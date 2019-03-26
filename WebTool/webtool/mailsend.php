<?php
	if(!isset($_POST['SendMail']))
	{
		print("エラー<br />\n");
		print("<a href=\"index.php\">トップページへ<br />\n");
		return;
	}
	
	print("送信しました。<br />\n");
	print("<a href=\"index.php\">トップページへ<br />\n");
?>
