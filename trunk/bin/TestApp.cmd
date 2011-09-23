@echo off
cd /D %~dp0
"%~dpn0.exe" -mnt=mountlist_packed.ini -projectfile=Projects -worldfile=World -disablecrashdumps -nomenu -res=1024x768 -window -devmode -enginelog -messagelog > %~dpn0.exe.silent.log
