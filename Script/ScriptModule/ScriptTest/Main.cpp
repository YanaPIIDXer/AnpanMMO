#include <iostream>
#include <stdio.h>
#include "Script/ScriptExecuter.h"

int main()
{
	ScriptExecuter Executer;

	std::cout << "Enterキーを押してください。" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
