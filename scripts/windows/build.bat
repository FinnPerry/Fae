@echo off
pushd ..\..\build\
msbuild fae.sln
set e=%errorlevel%
popd
exit /b %e%
