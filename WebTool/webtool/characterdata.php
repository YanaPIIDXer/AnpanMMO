<?php
	require_once('funcs\\session.php');
	session_start();
	if(RedirectIfNotLogIn('userdata.php')){ return; }
	
	// ���������擾.
	function GetEquipName($Id)
	{
		$Conn = MasterConnectionWithSession();
		if(!$Conn)
		{
			print("Master DB Connection Error.<br />\n");
			return "";
		}
		
		$Stmt = $Conn->prepare("select Name from Equip where ID = :ID;");
		if(!$Stmt)
		{
			print("GetEquipName() Prepare Failed.<br />\n");
			print($Conn->errorInfo() . "<br />\n");
			return "";
		}
		
		$Stmt->bindValue(':ID', $Id, PDO::PARAM_INT);
		$Stmt->execute();
		$Row = $Stmt->fetch(PDO::FETCH_ASSOC);
		if(!$Row) { return ""; }
		
		$Name = $Row['Name'];
		return $Name;
	}
?>

<html>
<head>
<title>�L�����N�^�f�[�^</title>
</head>
<body>
<h1>�L�����N�^�f�[�^</h1><hr />
<?php
	require_once("funcs\\database.php");
	
	$Conn = DBConnectionWithSession();
	if(!$Conn)
	{
		print("DB Connection Error<br />\n");
		return;
	}
	
	if(!isset($_POST['CustomerId']))
	{
		print("�G���[�B<a href=\"userdata.php\">���[�U�f�[�^�y�[�W</a>�����蒼���Ă��������B<br />\n");
		return;
	}
	
	$CustomerId = $_POST['CustomerId'];
	
	// �L�����N�^�f�[�^�e�[�u���̍\�z.
	$Stmt = $Conn->prepare("select Name, Level, Exp, RightEquip, LeftEquip, IsGM from CharacterData where CustomerId = :CustomerId;");
	$Stmt->bindValue(':CustomerId', $CustomerId, PDO::PARAM_INT);
	$Stmt->execute();
	print("<table border=1>\n");
	print("<caption>���[�U�f�[�^</caption>\n");
	print("<tr style=\"background:#FF00CC\">\n");
	print("<th>�L�����N�^��</th>\n");
	print("<th>���x��</th>\n");
	print("<th>�o���l</th>\n");
	print("<th>�E�葕��</th>\n");
	print("<th>���葕��</th>\n");
	print("<th>�f�l�t���O</th>\n");
	print("</tr>\n");
	while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
	{
		print("<tr>\n");
		print("<th>" . $Row['Name'] . "</th>\n");
		print("<th>" . $Row['Level'] . "</th>\n");
		print("<th>" . $Row['Exp'] . "</th>\n");
		$RightEquip = GetEquipName($Row['RightEquip']);
		$LeftEquip = GetEquipName($Row['LeftEquip']);
		print("<th>" . $RightEquip . "</th>\n");
		print("<th>" . $LeftEquip . "</th>\n");
		$GMFlag = "";
		if($Row['IsGM'] == '1')
		{
			$GMFlag = "��";
		}
		print("<th>" . $GMFlag . "</th>\n");
		print("</tr>\n");
	}
	print("</table><br />\n");
?>
</body>
</html>
