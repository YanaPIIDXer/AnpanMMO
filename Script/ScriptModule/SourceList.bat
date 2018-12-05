@echo off
setlocal enabledelayedexpansion
set BSLASH=\
set CD_S=%CD%%BSLASH%
set RESULT=
for /f "usebackq tokens=*" %%i in (`dir /s /b /a-d ScriptModule\*.cpp`) do (
  set RESULT=!RESULT!^

%%i
)
set LIST_SUB=!RESULT:%CD_S%=!
set /p LIST=!LIST_SUB!<nul
endlocal