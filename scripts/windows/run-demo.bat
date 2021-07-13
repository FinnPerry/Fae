@echo off
pushd ..\..\build\fae-demo\Debug\
call fae-demo.exe
set e=%errorlevel%
popd
exit /b %e%
