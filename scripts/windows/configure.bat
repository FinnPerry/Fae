@echo off
mkdir ..\..\build
pushd ..\..\build
cmake -G Ninja ..\
popd
exit /b %errorlevel%
