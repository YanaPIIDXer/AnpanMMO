<?php
	// アラート（単純なダイアログ）表示.
	function ShowAlert($Message)
	{
		print("<script>\n");
		print("	alert(\"" . $Message . "\");\n");
		print("</script>\n");
	}
?>