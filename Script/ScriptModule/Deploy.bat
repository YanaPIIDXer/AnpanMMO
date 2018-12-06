@echo off

rem Deploy to Client
set INCLUDE=ScriptModule\Script\*.h
set SOURCES=ScriptModule\Script\*.cpp
set CLIENT_MODULE_ROOT=..\..\Client\AnpanMMO\Source\ScriptModule\
set CLIENT_INCLUDE=%CLIENT_MODULE_ROOT%
set CLIENT_SOURCES=%CLIENT_MODULE_ROOT%
copy %INCLUDE% %CLIENT_INCLUDE%
copy %SOURCES% %CLIENT_SOURCES%

rem Deploy to Server
set SERVER_DIR=..\..\Server\AnpanMMOServer\
copy %INCLUDE% %SERVER_DIR%\Script\
copy %SOURCES% %SERVER_DIR%\Script\

pause
