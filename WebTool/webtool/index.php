<?php
	require "funcs\\session.php";
	if(!RedirectIfNotLogIn('index.php')){ return; }
	print("Test<br />\n");
?>