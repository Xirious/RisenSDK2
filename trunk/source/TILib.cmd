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
echo   * %~n0{BaseName}.cfg and %~n0{BaseName}.tih exist.
echo.
pause
exit /B 1
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
"%IDAROOT%\tilib.exe" -c %2 "@%~dpn0%DLLNAME%.cfg" "-h%~dpn0%DLLNAME%.tih" "-DDLLIMPORT=*" "%TILNAME%.til"
popd
if errorlevel 1 (
  endlocal
  pause
  exit /B 2
)

if "%2"=="-u+" (
  pushd "%TILPATH%"
  "%IDAROOT%\tilib.exe" -l "%TILNAME%.til" > "%TILNAME%.txt"
  popd
)

pushd "%TILPATH%"
echo %CD%\%TILNAME%_dll.til
"%IDAROOT%\tilib.exe" -c %2 "@%~dpn0%DLLNAME%.cfg" "-h%~dpn0%DLLNAME%.tih" "-DDLLIMPORT=" "%TILNAME%_dll.til"
popd
if errorlevel 1 (
  endlocal
  pause
  exit /B 3
)

if "%2"=="-u+" (
  pushd "%TILPATH%"
  "%IDAROOT%\tilib.exe" -l "%TILNAME%_dll.til" > "%TILNAME%_dll.txt"
  popd
)

set IDSNAMES=%IDAROOT%\ids\idsnames
find /I "%DLLNAME%.ids" "%IDSNAMES%"
if errorlevel 1 (
  echo.>>                                                              "%IDSNAMES%"
  echo ; [Risen]\bin\%DLLNAME%.dll>>                                   "%IDSNAMES%"
  echo %DLLNAME%.ids Risen%DLLNAME%.ids - pc ? 32 ? Risen%DLLNAME%;;>> "%IDSNAMES%"
  echo %DLLNAME%.ids Risen%DLLNAME%.ids - pc ? 32 ? Risen%DLLNAME%;;
)
echo.

endlocal
exit /B 0
