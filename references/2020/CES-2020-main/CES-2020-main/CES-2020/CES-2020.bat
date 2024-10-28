@TITLE CES-2020
:start
cls
@echo off
chcp 1251>nul
echo 1 - Использовать стандартные значения ключей
echo 2 - Изменить имя log и an файлов
echo 3 - Выход
choice /C:123 /M:"Сделайте выбор " /N /D:1 /T 10
if errorlevel 3 goto exit
if errorlevel 2 goto m2
if errorlevel 1 goto m1

:m2
	if NOT EXIST in.txt (echo Отсутствует файл с исходным кодом & pause & goto :EOF)
	set /p log="Введите имя log-файла: "
	if "%log%"=="" (echo Некорректное имя файла, попробуйте снова & pause & goto start)
	set /p an="Введите имя an-файла: "
	if "%an%"=="" (echo Некорректное имя файла, попробуйте снова & pause & goto start)
	call debug\ces-2020.exe /in:in.txt /log:%log% /an:%an%
	goto next
:m1
	if NOT EXIST in.txt (echo Отсутствует файл с исходным кодом & pause & goto :EOF)
	call debug\ces-2020.exe /in:in.txt 	
:next
	echo @echo off>helper.bat
	echo ml /nologo /c in.txt.asm>>helper.bat
	echo link /NOLOGO /out:asm.exe in.txt.obj ..\CES-2020\Debug\CES-2020L.lib /SUBSYSTEM:CONSOLE /IGNORE:4098 /IGNORE:4075>>helper.bat
	echo cls>>helper.bat
	echo call asm.exe>>helper.bat
	%comspec% /k "%devCMDPath% -no_logo & helper.bat"
