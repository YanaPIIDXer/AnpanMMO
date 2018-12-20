@echo off
set DOCUMENT_ROOT=%WORKSPACE%\docs\SourceDocument

rem Client
cd %DOCUMENT_ROOT%\Client\
doxygen Doxyfile

rem Server
cd %DOCUMENT_ROOT%\Server\GameServer\
doxygen Doxyfile

rem Commit and Push
cd %DOCUMENT_ROOT%
git add *
git commit -m "�h�L�������g�̍X�V�B"
git push origin master
