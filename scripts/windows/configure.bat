@echo off
mkdir ..\..\build
pushd ..\..\build
cmake ..\
set e=%errorlevel%
popd
exit /b %e%
