@echo off
gcc -o ./dist/calc ./src/main.c
echo calc.exe built
gcc -o ./dist/rel ./src/rel.c
echo rel.exe built
echo All files built succesfully