@echo off
echo Compiling with debug symbols...
g++ -g -O0 -o lab02-debug lab02-main.cpp -std=c++11
echo Compilation complete!
echo Run with: lab02-debug.exe
pause
