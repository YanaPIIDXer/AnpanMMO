<?php
	// ログインしているかどうか？
	function IsLogIn()
	{
		session_start();
		
		if(!isset($_SESSION['DBUserName'])) { return false; }
		if(!isset($_SESSION['DBPassword'])) { return false; }
		
		return true;
	}
	
	// ログインしていなければリダイレクトする。
	// ※リダイレクトした場合はtrueを返す。
	function RedirectIfNotLogIn()
	{
		if(!IsLogIn())
		{
			header('Location: login.php');
			return true;
		}
		return false;
	}
	
?>