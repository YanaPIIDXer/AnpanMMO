<?php
	// �c�a�ڑ��I�u�W�F�N�g�擾.
	function DBConnection($UserName, $Password)
	{
		$Conn = mysql_connect('localhost', $UserName, $Password);
		return $Conn;
	}
?>
