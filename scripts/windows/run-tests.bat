@echo off
pushd ..\..\build\tests\Debug\
call fae-tests.exe
set e=%errorlevel%
popd
exit /b %e%
