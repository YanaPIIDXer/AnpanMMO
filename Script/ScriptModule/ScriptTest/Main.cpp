#include <iostream>
#include <stdio.h>
#include "Script\Include/ScriptExecuter.h"

int main()
{
	ScriptExecuter::GetInstnace().ExecuteTest();

	std::cout << "Enterキーを押してください。" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
