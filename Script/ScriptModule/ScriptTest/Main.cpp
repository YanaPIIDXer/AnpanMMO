#include <iostream>
#include <stdio.h>
#include "Script/ScriptExecuter.h"

int main()
{
	ScriptExecuter Executer;
	Executer.ExecuteTest();

	std::cout << "Enter�L�[�������Ă��������B" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
