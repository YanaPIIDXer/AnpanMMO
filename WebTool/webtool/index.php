<?php
	require "funcs\\session.php";
	if(!RedirectIfNotLogIn()){ return; }
	print("Test<br />\n");
?>