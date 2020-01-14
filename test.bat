@echo off
echo Without removing the whitespace
cat testfile.txt | .\dist\calc.exe
echo.
echo After removing the whitespace
cat testfile.txt | .\dist\rtws.exe | .\dist\calc.exe