set "OutputDir=%1"
set "Configuration=%2"

rem Debugging
rem echo %OutputDir% > log.txt

cd %OutputDir%

(robocopy ..\..\..\..\..\CelesteEngine\CelesteEngine\bin\Win32\%Configuration%\ .\ /IS /IT) ^&
(robocopy ..\..\..\..\..\CelesteEngine\BindingsGenerator\bin\Win32\%Configuration%\ .\ /IS /IT) ^& exit 0