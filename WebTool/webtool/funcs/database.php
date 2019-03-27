<?php
	// �c�a�ڑ��I�u�W�F�N�g�擾.
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
	
	// �Z�b�V��������c�a�ڑ��I�u�W�F�N�g���擾.
	function DBConnectionWithSession()
	{
		$Conn = DBConnection($_SESSION['DBUserName'], $_SESSION['DBPassword']);
		return $Conn;
	}
	
	// �}�X�^�ڑ��I�u�W�F�N�g�擾.
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
	
	// �Z�b�V��������}�X�^�ڑ��I�u�W�F�N�g���擾.
	function MasterConnectionWithSession()
	{
		$Conn = MasterConnection($_SESSION['MasterUserName'], $_SESSION['MasterPassword']);
		return $Conn;
	}
?>
