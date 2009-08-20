REM Start
w:
cd w:\boomworks\SrcCounter

REM Make target dir
mkdir release\sourcecounter

REM Copy .exe .xml file to target dir
copy /Y src\bin\release\*.exe release\sourcecounter\
copy /Y src\*.xml release\sourcecounter\

REM Xcopy img and locales file to target dir
xcopy /Y /f /s src\img\*.* release\sourcecounter\img\
xcopy /Y /f /s src\locales\*.mo release\sourcecounter\locales\
xcopy /Y /f /s src\locales\*.po release\sourcecounter\locales\

REM Copy .dll .txt file to SourceCounter
cd release\
copy /Y *.dll sourcecounter\
copy /Y *.txt sourcecounter\

REM Make dir oldversion
mkdir oldversion

REM Copy .zip .7z file to old verison folder
copy /Y *.zip oldversion\
copy /Y *.7z oldversion\

REM Delete 7z zip files
del *.7z *.zip

REM Make 7z file | 7z a -t7z Files.7z *.txt -r
7z a -t7z SourceCounter-2.4.91.2.7z SourceCounter\ -mx7

REM Make zip file
7z a -tzip SourceCounter-2.4.91.2.zip SourceCounter\ -mx9

REM End