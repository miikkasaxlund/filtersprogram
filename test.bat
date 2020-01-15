@echo off

if [%1] == [] (
  echo No test was defined
  Exit /b
) else (
  SET /A testn=%1
)

:: Calculate the number of chars, whitespaces, words and lines 
:: from the source files created in this assignment
if %testn%==1 (
  echo Test case A
  for %%f in (./src/*.c) do (
    echo.
    echo Calculating %%f
    cat .\src\%%f | .\dist\calcf.exe
    echo.
  )
)

:: Calculate the number of chars, whitespaces, words and lines 
:: from the source files created in this assignment. Before the
:: calculations remove consecutive whitespace and empty lines
if %testn%==2 (
  echo Test case B
  for %%f in (./src/*.c) do (
    echo.
    echo Calculating %%f
    cat .\src\%%f | .\dist\rcws.exe | .\dist\rel.exe | .\dist\calcf.exe
    echo.
  )
)

:: Calculate the number of chars, whitespaces, words and lines 
:: from the source files created in this assignment. Before the
:: calculations remove whitespace, empty lines and comments
if %testn%==3 (
  echo Test case C
  for %%f in (./src/*.c) do (
    echo.
    echo Calculating %%f
    cat .\src\%%f | .\dist\rws.exe | .\dist\rel.exe | .\dist\rc.exe | .\dist\rcb.exe | .\dist\calcf.exe
    echo.
  )
)