#include <iostream>
#include <stdio.h>
#include "Script\Include/ScriptExecuter.h"

int main()
{
	ScriptExecuterBase Executer;
	Executer.ExecuteTest();

	std::cout << "Enter�L�[�������Ă��������B" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
