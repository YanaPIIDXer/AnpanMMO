@echo off
set DOCUMENT_ROOT=%WORKSPACE%\docs\SourceDocument

rem fetch remote branch
git fetch origin Work
git checkout Work
git merge origin/Work

rem Client
cd %DOCUMENT_ROOT%\Client\
doxygen Doxyfile

rem Server
cd %DOCUMENT_ROOT%\Server\GameServer\
doxygen Doxyfile

rem Tool
cd %DOCUMENT_ROOT%\Tool\MasterConverter\
doxygen Doxyfile

cd %DOCUMENT_ROOT%\Tool\PacketGenerator\
doxygen Doxyfile

rem Commit and Push
cd %DOCUMENT_ROOT%
git add *
git commit -m "ドキュメントの更新。"
git pull origin Work
git push origin Work
