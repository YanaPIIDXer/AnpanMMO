<?php	
	// ログインしているかどうか？
	function IsLogIn()
	{
		if(!isset($_SESSION['DBUserName'])) { return false; }
		if(!isset($_SESSION['DBPassword'])) { return false; }
		
		// ＤＢ接続チェック
		require_once('database.php');
		$Conn = DBConnectionWithSession();
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