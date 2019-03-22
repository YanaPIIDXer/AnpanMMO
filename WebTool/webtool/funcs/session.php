<?php	
	// ログインしているかどうか？
	function IsLogIn()
	{
		session_start();
		
		if(!isset($_SESSION['DBUserName'])) { return false; }
		if(!isset($_SESSION['DBPassword'])) { return false; }
		
		// ＤＢ接続チェック
		require_once('database.php');
		$Conn = DBConnection($_SESSION['DBUserName'], $_SESSION['DBPassword']);
		if(!$Conn) { return false; }
		
		return true;
	}
	
	// ログインしていなければリダイレクトする。
	// ※リダイレクトした場合はtrueを返す。
	function RedirectIfNotLogIn($From)
	{
		if(!IsLogIn())
		{
			header('Location: login.php?from=' . $From);
			return true;
		}
		return false;
	}
	
?>