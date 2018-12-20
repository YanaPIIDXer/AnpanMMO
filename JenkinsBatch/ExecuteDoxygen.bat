@echo off
set DOCUMENT_ROOT=%WORKSPACE%\docs\SourceDocument

rem Client
cd %DOCUMENT_ROOT%\Client\
doxygen Doxyfile

rem Server
cd %DOCUMENT_ROOT%\Server\GameServer\
doxygen Doxyfile
