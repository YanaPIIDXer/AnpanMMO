#include <iostream>
#include <stdio.h>
#include "Script\Include/ScriptExecuter.h"

int main()
{
	ScriptExecuterBase Executer;
	Executer.ExecuteTest();

	std::cout << "Enterキーを押してください。" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
