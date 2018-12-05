@echo off

rem Windows x86
devenv /rebuild "release|x86" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Windows x64
devenv /rebuild "release|x64" /out BuildLog/build.log ScriptModule\ScriptModule.vcxproj /project ScriptModule

rem Linux and Mobiles
GenerateMakeFile
make

pause
