@echo off
mkdir ..\..\build
pushd ..\..\build
cmake -G Ninja ..\
set e=%errorlevel%
popd
exit /b %e%
