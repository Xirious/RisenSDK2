@echo off
cd /D "%~dp0"
for /R %%i in (*.aps) do del "%%i"
for /R %%i in (*.ncb) do del "%%i"
attrib -H *.suo /S
for /R %%i in (*.suo) do del "%%i"
for /R %%i in ("*.vcproj.%COMPUTERNAME%.%USERNAME%.user") do del "%%i"
