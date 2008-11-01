REM Start
w:
cd w:\boomworks\SrcCounter

copy /Y src\bin\release\*.exe release\sourcecounter\
xcopy /Y /f /s src\img\*.* release\sourcecounter\img\
xcopy /Y /f /s src\locales\*.mo release\sourcecounter\locales\

cd release\
copy /Y *.dll sourcecounter\
copy /Y *.txt sourcecounter\

REM delete 7z zip files
del *.7z *.zip

REM 7z a -t7z Files.7z *.txt -r
7z a -t7z sourcecounter-2.0.10.61.7z SourceCounter\
REM zip
7z a -tzip sourcecounter-2.0.10.61.zip SourceCounter\ -mx9

REM End