@echo off
pushd ..\..\
rmdir /s /q .\build\
set e=%errorlevel%
popd
exit /b %e%
