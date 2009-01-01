REM Start
w:
cd w:\boomworks\DeskAssistant

mkdir release\DeskAssistant

copy /Y src\bin\release\*.exe release\DeskAssistant\
copy /Y src\*.xml release\DeskAssistant\

xcopy /Y /f /s src\img\*.* release\DeskAssistant\img\
xcopy /Y /f /s src\locales\*.mo release\DeskAssistant\locales\
xcopy /Y /f /s src\locales\*.po release\DeskAssistant\locales\

cd release\
copy /Y *.dll DeskAssistant\
copy /Y *.txt DeskAssistant\

REM copy zip to old verison folder
mkdir oldversion

copy /Y *.zip oldversion\
copy /Y *.7z oldversion\

delete 7z zip files
del *.7z *.zip

REM 7z a -t7z Files.7z *.txt -r
7z a -t7z DesktopAssistant-1.2.12.18.7z DeskAssistant\ -mx7
REM zip
7z a -tzip DesktopAssistant-1.2.12.18.zip DeskAssistant\ -mx9

REM End