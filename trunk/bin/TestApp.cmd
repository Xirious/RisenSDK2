@echo off
cd /D %~dp0
"%~dpn0.exe" -mnt=mountlist_packed.ini -projectfile=Projects -worldfile=World -disablecrashdumps -nomenu -nointro -devmode
