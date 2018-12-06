@echo off

rem Deploy to Client
set INCLUDE=ScriptModule\Script\Include\*
set SOURCES=ScriptModule\Script\*
set CLIENT_MODULE_ROOT=..\..\Client\AnpanMMO\Source\ScriptModule\
set CLIENT_INCLUDE=%CLIENT_MODULE_ROOT%Include\
set CLIENT_SOURCES=%CLIENT_MODULE_ROOT%Sources\
copy %INCLUDE% %CLIENT_INCLUDE%
copy %SOURCES% %CLIENT_SOURCES%

rem Deploy to Server
set SERVER_DIR=..\..\Server\AnpanMMOServer\
copy %INCLUDE% %SERVER_DIR%\Script\Include\
copy %SOURCES% %SERVER_DIR%\Script\

pause
