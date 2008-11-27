REM Start
w:
cd w:\boomworks\SrcCounter

REM mkdir
mkdir release\sourcecounter

copy /Y src\bin\release\*.exe release\sourcecounter\
xcopy /Y /f /s src\img\*.* release\sourcecounter\img\
xcopy /Y /f /s src\locales\*.mo release\sourcecounter\locales\
xcopy /Y /f /s src\locales\*.po release\sourcecounter\locales\

REM End