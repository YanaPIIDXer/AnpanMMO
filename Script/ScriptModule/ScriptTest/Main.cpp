#include <iostream>
#include <stdio.h>
#include "Script/ScriptExecuter.h"
#include <fstream>

int main()
{
	std::ifstream ScriptStream("LuaScript\\TestScript.lua");
	if (!ScriptStream)
	{
		std::cout << "スクリプトの読み込みに失敗しました。" << std::endl;
		std::cout << "Enterキーを押してください。" << std::endl;
		while ((getchar() != '\n'));
		return 1;
	}

	std::string Script = "";
	while (!ScriptStream.eof())
	{
		std::string Line;
		ScriptStream >> Line;
		Script += Line + "\n";
	}

	ScriptExecuter Executer;
	Executer.SetScriptDir("LuaScript");
	Executer.ExecuteScript(Script.c_str());
	
	std::cout << "Enterキーを押してください。" << std::endl;
	while ((getchar() != '\n'));
	return 0;
}
