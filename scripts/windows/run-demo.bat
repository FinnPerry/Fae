@echo off
pushd ..\..\build\demo\
call fae-demo.exe
popd
exit /b %errorlevel%
