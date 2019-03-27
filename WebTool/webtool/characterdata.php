<?php
	require_once('funcs\\session.php');
	session_start();
	if(RedirectIfNotLogIn('userdata.php')){ return; }
	
	// 装備名を取得.
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
<title>キャラクタデータ</title>
</head>
<body>
<h1>キャラクタデータ</h1><hr />
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
		print("エラー。<a href=\"userdata.php\">ユーザデータページ</a>からやり直してください。<br />\n");
		return;
	}
	
	$CustomerId = $_POST['CustomerId'];
	
	// キャラクタデータテーブルの構築.
	$Stmt = $Conn->prepare("select Name, Level, Exp, RightEquip, LeftEquip, IsGM from CharacterData where CustomerId = :CustomerId;");
	$Stmt->bindValue(':CustomerId', $CustomerId, PDO::PARAM_INT);
	$Stmt->execute();
	print("<table border=1>\n");
	print("<caption>ユーザデータ</caption>\n");
	print("<tr style=\"background:#FF00CC\">\n");
	print("<th>キャラクタ名</th>\n");
	print("<th>レベル</th>\n");
	print("<th>経験値</th>\n");
	print("<th>右手装備</th>\n");
	print("<th>左手装備</th>\n");
	print("<th>ＧＭフラグ</th>\n");
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
			$GMFlag = "○";
		}
		print("<th>" . $GMFlag . "</th>\n");
		print("</tr>\n");
	}
	print("</table><br />\n");
?>
<a href="userdata.php">ユーザデータページに戻る</a>
</body>
</html>
