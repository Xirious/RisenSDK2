@echo off
setlocal
setlocal enabledelayedexpansion

set LIST=Engine.dll FFC.dll FFCore.dll FileSystem2.dll Game.dll GUI2.dll Importer.dll Music.dll SCM.dll Script.dll SharedBase.dll scripts\Script_Game.dll

for /L %%i in (8,1,10) do (
  if "!VSCOMMONTOOLS!" == "" (
    if exist "!VS%%i0COMNTOOLS!vsvars32.bat" (
      set VSCOMMONTOOLS=!VS%%i0COMNTOOLS!
    )
  )
)

if not exist "!VSCOMMONTOOLS!vsvars32.bat" (
  echo.
  echo Failed to detect your Visual Studio installation.
  echo.
  pause
) else (
  set PATH=!PATH!;%SystemRoot%\system32
  call "!VSCOMMONTOOLS!vsvars32.bat"
  if not exist "!VCINSTALLDIR!\vcvarsall.bat" (
    echo.
    echo Failed to detect your Visual C++ installation.
    echo.
    pause
  ) else (
    call "!VCINSTALLDIR!\vcvarsall.bat" x86
    cd /D "%~dp0"
    for %%i in (%LIST%) do (
      echo.
      echo [%%i]
      echo dump exports
      dumpbin.exe /exports /out:%%i.exports.tmp %%i > nul
      if exist %%i.exports.tmp (
        echo filter exports
        if exist %%i.exports.txt erase %%i.exports.txt
        for /F "tokens=1-3*" %%a in (%%i.exports.tmp) do (
          set ORDINAL=
          set HINT=
          set RVA=
          set /A ORDINAL=%%a 2> nul
          set /A HINT=0x%%b 2> nul
          set /A RVA=0x%%c 2> nul
          if not "!ORDINAL!" == "0" if not "!ORDINAL!" == "" if not "!HINT!" == "" if not "!RVA!" == "" (
            echo 0x%%c %%d >> %%i.exports.txt
          )
        )
        erase %%i.exports.tmp
        if exist %%i.exports.txt (
          echo unmangle exports
          undname.exe 0x8000 %%i.exports.txt > %%i.undname.txt
        )
      )
    )
    echo.
  )
)
endlocal
pause
