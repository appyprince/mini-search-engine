@echo off
echo Compiling source files in src\...

g++ -std=c++17 src\*.cpp -o search.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo [SUCCESS] Compilation finished: search.exe
) else (
    echo.
    echo [ERROR] Compilation failed! Please check your code.
)