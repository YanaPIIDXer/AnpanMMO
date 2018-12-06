@echo off

rem Windows x86_Debug
devenv /rebuild "debug|x86" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Windows x64_Debug
devenv /rebuild "debug|x64" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Windows x86_Release
devenv /rebuild "release|x86" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Windows x64_Release
devenv /rebuild "release|x64" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Linux and Mobiles
GenerateMakeFile
make

rem Deploy to Client
set INCLUDE=ScriptModule\Script\Include\*
set CLIENT_MODULE_ROOT=..\..\Client\AnpanMMO\Source\ScriptModule\
set CLIENT_INCLUDE=%CLIENT_MODULE_ROOT%Include\
set CLIENT_LIBRARY=%CLIENT_MODULE_ROOT%Libraries\
copy %INCLUDE% %CLIENT_INCLUDE%
copy ScriptModule_x64.lib %CLIENT_LIBRARY%
copy ScriptModule_x86.lib %CLIENT_LIBRARY%
copy libscriptmodule.a %CLIENT_LIBRARY%

rem Deploy to Server
set SERVER_DIR=..\..\Server\AnpanMMOServer\
copy %INCLUDE% %SERVER_DIR%\Script\
copy ScriptModule_x64.lib %SERVER_DIR%\Lib
copy ScriptModule_x86.lib %SERVER_DIR%\Lib
copy ScriptModule\ScriptModule_x64_Debug.lib %SERVER_DIR%\Lib
copy ScriptModule\ScriptModule_x86_Debug.lib %SERVER_DIR%\Lib
copy libscriptmodule.a %SERVER_DIR%\Lib

pause
