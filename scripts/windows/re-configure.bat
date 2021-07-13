@echo off
call clean.bat && call configure.bat
exit /b %errorlevel%
