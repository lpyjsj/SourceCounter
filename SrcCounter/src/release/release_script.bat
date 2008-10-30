REM Start
w:
cd w:\boomworks\SrcCounter\src

copy /Y bin\release\*.exe release\sourcecounter\
xcopy /Y /f /s img\*.* release\sourcecounter\img\
xcopy /Y /f /s locales\*.mo release\sourcecounter\locales\

cd release\

REM delete 7z zip files
del *.7z *.zip

REM 7z a -t7z Files.7z *.txt -r
7z a -t7z SourceCounter-2.0.7z SourceCounter\
REM zip
7z a -tzip SourceCounter-2.0.zip SourceCounter\ -mx9

REM End