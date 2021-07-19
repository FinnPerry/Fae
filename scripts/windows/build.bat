@echo off
pushd ..\..\build\
ninja
popd
exit /b %errorlevel%
