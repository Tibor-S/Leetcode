@echo off
setlocal enabledelayedexpansion
for /r %%i in (*.cpp) do (
    set opath=%%i
    set npath=!opath:_=-!
    git mv !opath! !npath!
)