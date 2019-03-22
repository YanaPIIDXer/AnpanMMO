<?php
	// ＤＢ接続オブジェクト取得.
	function DBConnection($UserName, $Password)
	{
		$Conn = false;
		try
		{
			$Conn = new PDO("mysql:dbname=AnpanMMO;host=127.0.0.1", $UserName, $Password);
		}
		catch(PDOException $e)
		{
			return false;
		}
		return $Conn;
	}
?>
