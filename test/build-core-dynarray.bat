@echo off
set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_BASE_PATH%\bin
set PRJ_PATH=%PRJ_BASE_PATH%\core

MD bin

clang -Idynamic_array\include -o bin\dynarray.lib dynamic_array\src\*.c -fuse-ld=llvm-lib