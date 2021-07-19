@echo off
pushd ..\..\
rmdir /s /q .\build\
popd
exit /b %errorlevel%
