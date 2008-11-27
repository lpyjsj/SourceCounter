REM Start
w:
cd w:\boomworks\DeskAssistant

mkdir release\DeskAssistant

copy /Y src\bin\release\*.exe release\DeskAssistant\
xcopy /Y /f /s src\img\*.* release\DeskAssistant\img\
xcopy /Y /f /s src\locales\*.mo release\DeskAssistant\locales\
xcopy /Y /f /s src\locales\*.po release\DeskAssistant\locales\

REM End