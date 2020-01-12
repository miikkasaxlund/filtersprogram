@echo off
gcc -o ./dist/calc ./src/calc.c
echo calc.exe built succesfully
gcc -o ./dist/rel ./src/rel.c
echo rel.exe built succesfully
gcc -o ./dist/rc ./src/rc.c
echo rc.exe built succesfully
gcc -o ./dist/rcb ./src/rcb.c
echo rcb.exe built succesfully
echo All files built succesfully