@echo off
cls
echo MSVC Build-Prozess wird gestartet...
echo ------------------------------------

:: 1. Schritt: Kompilieren der Quellcode-Dateien zu .obj
:: /c unterdrückt das automatische Linken nach jedem Aufruf
:: /W4 aktiviert ein hohes Warn-Level für sauberen Code
cl /c /W4 main.c
cl /c /W4 CalcSqrt.c
cl /c /W4 CalcPrintSqrt.c

:: Prüfen, ob die Kompilierung erfolgreich war (%errorlevel% 0 bedeutet Erfolg)
if %errorlevel% neq 0 (
    echo.
    echo [FEHLER] Ein Fehler ist waehrend der Kompilierung aufgetreten.
    pause
    exit /b %errorlevel%
)

:: 2. Schritt: Linken der Objekte zur Test.exe
echo.
echo Linke Dateien zu Test.exe...
:: /link leitet die folgenden Parameter direkt an den Linker (link.exe) weiter
cl main.obj CalcSqrt.obj CalcPrintSqrt.obj /link /out:Test.exe

:: 3. Schritt: Aufraeumen
:: Löscht die temporären Objektdateien, um den Ordner sauber zu halten
del *.obj

echo.
echo Fertig! Starte Test.exe:
echo ------------------------------------
if exist Test.exe (
    Test.exe
) else (
    echo [FEHLER] Test.exe wurde nicht erstellt.
)

pause
