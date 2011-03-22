@for %%i in (SharedBase FFCore FileSystem2 GUI2 FFC Engine Music Game Importer Script Script_Game) do @(
  echo ////////////////////////////////////////////////////////////////////////////////
  echo //
  echo //  %%i.dll
  echo //
  echo.
  call "%~dp0TILib.cmd" %%i
)
