<?php
	require_once('funcs\\database.php');
	session_start();

	// メッセージとトップページへのリンクを表示。
	function DisplayMessage($Message)
	{
		print($Message . "<br />\n");
		print("<a href=\"index.php\">トップページへ</a><br />\n");
	}
	
	// メールフォームページへ戻す。
	// ※主に入力エラーがあった時に使用。
	function BackToMailForm($Message)
	{
		print($Message . "<br />\n");
		print("<form method=\"POST\" name=\"BackToForm\" action=\"mail.php\">\n");
		print("	<input type=\"hidden\" name=\"CustomerId\" value=" . $_POST['CustomerId'] . ">\n");
		print("	<a href=\"mail.php\" onclick=\"document.BackToForm.submit();return false;\">戻る</a><br />\n");
		print("</form>\n");
	}
	
	// 送信関数.
	function Send($CustomerId, $Subject, $Body, $AttachmentType, $AttachmentId, $AttachmentCount)
	{
		$Conn = DBConnectionWithSession();
		if(!$Conn)
		{
			DisplayMessage("ＤＢ接続エラー");
			return false;
		}
		
		$Stmt = $Conn->prepare("insert into Mail values(:CustomerId, :Subject, :Body, :AttachmentType, :AttachmentId, :AttachmentCount, :Date, 0);");
		$Stmt->bindValue(':CustomerId', $CustomerId, PDO::PARAM_INT);
		$Stmt->bindValue(':Subject', $Subject, PDO::PARAM_STR);
		$Stmt->bindValue(':Body', $Body, PDO::PARAM_STR);
		$Stmt->bindValue(':AttachmentType', $AttachmentType, PDO::PARAM_INT);
		$Stmt->bindValue(':AttachmentId', $AttachmentId, PDO::PARAM_INT);
		$Stmt->bindValue(':AttachmentCount', $AttachmentCount, PDO::PARAM_INT);
		$Stmt->bindValue(':Date', date("Y-m-d"), PDO::PARAM_STR);
		
		if(!$Stmt->execute())
		{
			DisplayMessage("ＳＱＬ実行エラー");
			return false;
		}
		
		return true;
	}
	
	if(!isset($_POST['SendMail']))
	{
		DisplayMessage("エラー");
		return;
	}

	// ＤＢにブチ込むデータ	
	$CustomerId = $_POST['CustomerId'];
	$Subject = htmlspecialchars($_POST['Subject']);
	$Body = htmlspecialchars($_POST['Body']);
	$AttachmentType = $_POST['AttachmentType'];
	$AttachmentId = $_POST['AttachmentId'];
	$AttachmentCount = $_POST['AttachmentCount'];

	// エラーチェック
	if($Subject == "")
	{
		BackToMailForm("本文が入力されていません。");
		return;
	}
	
	if($Body == "")
	{
		BackToMailForm("本文が入力されていません。");
		return;
	}
	
	if($AttachmentType != 0 && $AttachmentCount <= 0)
	{
		BackToMailForm("数量に０以下を指定する事は出来ません。");
		return;
	}
	
	
	// Ｄｂにブチ込む処理.
	$Conn = DBConnectionWithSession();
	if(!$Conn)
	{
		DisplayMessage("ＤＢ接続エラー");
		return;
	}
	if($CustomerId != -1)
	{
		// 個別送信.
		Send($CustomerId, $Subject, $Body, $AttachmentType, $AttachmentId, $AttachmentCount);
	}
	else
	{
		// 全員にブロードキャスト
		$Stmt = $Conn->query("select Id from UserData;");
		while($Row = $Stmt->fetch(PDO::FETCH_ASSOC))
		{
			$CustomerId = $Row['Id'];
			if(!Send($CustomerId, $Subject, $Body, $AttachmentType, $AttachmentId, $AttachmentCount)) { return; }
		}
	}
	
	DisplayMessage("送信しました。");
?>
