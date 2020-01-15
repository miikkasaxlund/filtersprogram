@echo off
gcc -o ./dist/calcf ./src/calcf.c
echo calcf.exe built succesfully
gcc -o ./dist/rel ./src/rel.c
echo rel.exe built succesfully
gcc -o ./dist/rc ./src/rc.c
echo rc.exe built succesfully
gcc -o ./dist/rcb ./src/rcb.c
echo rcb.exe built succesfully
gcc -o ./dist/rws ./src/rws.c
echo rws.exe built succesfully
gcc -o ./dist/rtws ./src/rtws.c
echo rws.exe built succesfully
gcc -o ./dist/rcws ./src/rcws.c
echo rcws.exe built succesfully
echo All files built succesfully