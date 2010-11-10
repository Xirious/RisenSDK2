@echo off
call "%VS80COMNTOOLS%vsvars32.bat"
call "%VCINSTALLDIR%\vcvarsall.bat" x86
cd /D "%~dp0"
for %%i in (Dialogs.dll Engine.dll FFC.dll FFCore.dll FileSystem2.dll Game.dll GUI2.dll Importer.dll Music.dll SCM.dll Script.dll SharedBase.dll) do (
  dumpbin.exe /exports /out:"%%~dpni.exports.txt" "%%i" && undname.exe 0x8000 "%%~dpni.exports.txt" > "%%~dpni.undname.txt"
)
