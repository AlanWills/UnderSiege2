set "OutputDir=%1"
set "Configuration=%2"

rem echo %OutputDir% > log.txt

cd %OutputDir%

(robocopy ..\..\..\..\..\CelesteEnginePlus\CelesteEnginePlus\bin\Win32\%Configuration%\ .\ /IS /IT) & exit 0