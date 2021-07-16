@echo off
pushd ..\..\build\demo\
call fae-demo.exe
set e=%errorlevel%
popd
exit /b %e%
