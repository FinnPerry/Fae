@echo off
pushd ..\..\build\tests\
call fae-tests.exe
popd
exit /b %errorlevel%
