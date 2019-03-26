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
	
	// セッションからＤＢ接続オブジェクトを取得.
	function DBConnectionWithSession()
	{
		$Conn = DBConnection($_SESSION['DBUserName'], $_SESSION['DBPassword']);
		return $Conn;
	}
	
	// マスタ接続オブジェクト取得.
	function MasterConnection($UserName, $Password)
	{
		$Conn = false;
		try
		{
			$Conn = new PDO("mysql:dbname=AnpanMMOMaster;host=127.0.0.1", $UserName, $Password);
		}
		catch(PDOException $e)
		{
			return false;
		}
		return $Conn;
	}
	
	// セッションからマスタ接続オブジェクトを取得.
	function MasterConnectionWithSession()
	{
		$Conn = MasterConnection($_SESSION['MasterUserName'], $_SESSION['MasterPassword']);
		return $Conn;
	}
?>
