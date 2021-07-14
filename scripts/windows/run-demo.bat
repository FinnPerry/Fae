@echo off
pushd ..\..\build\demo\Debug\
call fae-demo.exe
set e=%errorlevel%
popd
exit /b %e%
