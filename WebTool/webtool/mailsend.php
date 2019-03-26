<?php
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
	
	if(!isset($_POST['SendMail']))
	{
		DisplayMessage("エラー");
		return;
	}
	
	$Subject = htmlspecialchars($_POST['Subject']);
	$Body = htmlspecialchars($_POST['Body']);
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
	
	$AttachmentType = $_POST['AttachmentType'];
	if($AttachmentType != 0)
	{
		$AttachmentCount = $_POST['AttachmentCount'];
		if($AttachmentCount <= 0)
		{
			BackToMailForm("数量に０以下を指定する事は出来ません。");
			return;
		}
	}
	
	DisplayMessage("送信しました。");
?>
