<?php
	// ＤＢ接続オブジェクト取得.
	function DBConnection($UserName, $Password)
	{
		$Conn = mysql_connect('localhost', $UserName, $Password);
		return $Conn;
	}
?>
