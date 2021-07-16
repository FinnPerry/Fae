@echo off
pushd ..\..\build\
ninja
set e=%errorlevel%
popd
exit /b %e%
