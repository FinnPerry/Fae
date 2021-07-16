@echo off
pushd ..\..\build\tests\
call fae-tests.exe
set e=%errorlevel%
popd
exit /b %e%
