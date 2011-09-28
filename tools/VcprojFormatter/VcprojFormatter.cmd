@echo off
echo.
if [%1]==[] (
  echo Please pass one or more *.vcproj as parameter.
  goto done
)
"%~dpn0.exe" -DECIMAL_POINT:. -ENCODING:UTF-8 -NEWLINE:CRLF - %*
echo.
echo Please do not forget to remove the BOM and to
echo re-order the Configuration blocks if required.
:done
echo.
pause
