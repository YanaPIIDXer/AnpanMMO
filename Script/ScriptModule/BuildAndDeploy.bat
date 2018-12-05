@echo off

rem Windows x86
devenv /rebuild "release|x86" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Windows x64
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
copy libscriptmodule.a %SERVER_DIR%

pause
