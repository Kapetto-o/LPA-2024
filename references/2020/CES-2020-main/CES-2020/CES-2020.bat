@TITLE CES-2020
:start
cls
@echo off
chcp 1251>nul
echo 1 - ������������ ����������� �������� ������
echo 2 - �������� ��� log � an ������
echo 3 - �����
choice /C:123 /M:"�������� ����� " /N /D:1 /T 10
if errorlevel 3 goto exit
if errorlevel 2 goto m2
if errorlevel 1 goto m1

:m2
	if NOT EXIST in.txt (echo ����������� ���� � �������� ����� & pause & goto :EOF)
	set /p log="������� ��� log-�����: "
	if "%log%"=="" (echo ������������ ��� �����, ���������� ����� & pause & goto start)
	set /p an="������� ��� an-�����: "
	if "%an%"=="" (echo ������������ ��� �����, ���������� ����� & pause & goto start)
	call debug\ces-2020.exe /in:in.txt /log:%log% /an:%an%
	goto next
:m1
	if NOT EXIST in.txt (echo ����������� ���� � �������� ����� & pause & goto :EOF)
	call debug\ces-2020.exe /in:in.txt 	
:next
	echo @echo off>helper.bat
	echo ml /nologo /c in.txt.asm>>helper.bat
	echo link /NOLOGO /out:asm.exe in.txt.obj ..\CES-2020\Debug\CES-2020L.lib /SUBSYSTEM:CONSOLE /IGNORE:4098 /IGNORE:4075>>helper.bat
	echo cls>>helper.bat
	echo call asm.exe>>helper.bat
	%comspec% /k "%devCMDPath% -no_logo & helper.bat"
