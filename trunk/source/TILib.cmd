@echo off
if not "%1"=="" goto :init
echo.
echo Usage:
echo.
echo   %~nx0 BaseName [additional TILib.exe parameters]
echo.
echo Requirements:
echo.
echo   * Type Information Library Utility (tilib.exe) v1.20
echo     extracted/installed in the root folder of IDA Pro.
echo   * Environment variable set (IDAROOT or NLSPATH) that
echo     points to the root folder of the IDA installation.
echo     (the default is C:\IDA if both values are missing)
echo   * Existing .\%~n0{BaseName}.cfg + .\{BaseName}.tih.
echo.
pause
goto :eof
:init
setlocal

if "%IDAROOT%"=="" set IDAROOT=%NLSPATH%
if "%IDAROOT%"=="" set IDAROOT=C:\IDA
if "%NLSPATH%"=="" set NLSPATH=%IDAROOT%

set DLLNAME=%1
set TILNAME=Risen%DLLNAME%
set TILPATH=%IDAROOT%\til\pc

pushd "%TILPATH%"
echo %CD%\%TILNAME%.til
"%IDAROOT%\tilib.exe" -c %2 "@%~dpn0%DLLNAME%.cfg" "-h%~dp0%DLLNAME%.tih" "-DDLLIMPORT=*" "%TILNAME%.til"
popd
if errorlevel 1 (
  pause
  goto :done
)

if "%2"=="-u+" (
  pushd "%TILPATH%"
  "%IDAROOT%\tilib.exe" -l "%TILNAME%.til" > "%TILNAME%.txt"
  popd
)

pushd "%TILPATH%"
echo %CD%\%TILNAME%_dll.til
"%IDAROOT%\tilib.exe" -c %2 "@%~dpn0%DLLNAME%.cfg" "-h%~dp0%DLLNAME%.tih" "-DDLLIMPORT=" "%TILNAME%_dll.til"
popd
if errorlevel 1 (
  pause
  goto :done
)

if "%2"=="-u+" (
  pushd "%TILPATH%"
  "%IDAROOT%\tilib.exe" -l "%TILNAME%_dll.til" > "%TILNAME%_dll.txt"
  popd
)

:done
endlocal
