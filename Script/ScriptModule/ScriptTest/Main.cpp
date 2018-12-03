#include <iostream>
#include <stdio.h>
#include "Script\Include/ScriptExecuter.h"

int main()
{
	ScriptExecuterBase Executer;
	Executer.ExecuteTest();

	std::cout << "EnterƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
