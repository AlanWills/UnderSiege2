set "OutputDir=%1"
set "Configuration=%2"
set "Platform=%3"

rem Debugging
rem echo %OutputDir% > log.txt

cd %OutputDir%

(robocopy ..\..\..\..\CelesteEngine\CelesteEngine\bin\%Platform%\%Configuration%\ .\ /IS /IT /xo) ^&
(robocopy ..\..\..\..\CelesteEngine\BindingsGenerator\bin\%Platform%\%Configuration%\ .\ /IS /IT /xo) ^& 
(robocopy ..\..\..\..\UnderSiege\bin\%Platform%\%Configuration%\ .\ /IS /IT /xo) ^& exit 0