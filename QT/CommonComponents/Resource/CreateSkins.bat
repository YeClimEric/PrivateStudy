REM ������ʼ��
set CURDIR=%~dp0%
set IMAGEDIRNAME=images
set QSSFILENAME=Skins
set IMAGEDIR=%CURDIR%%IMAGEDIRNAME%\
set QRCFILE=%CURDIR%%QSSFILENAME%.qrc
set QSSFILE=%CURDIR%%QSSFILENAME%.qss
set SKINCONFITFILE=%CURDIR%\SkinConfig.txt
set MULTISKIN=FALSE
::REM	��ʼ��ȡƤ�������ļ�
::if exist %SKINCONFITFILE% set MULTISKIN=TRUE
::REM ��ʼ��̬����Ƥ����ʽ�ļ�
::
::pushd %CURDIR%
::
::if "%MULTISKIN%" == "TRUE" (
::	REM ��ʼ���������ļ�
::	for /f "tokens=1" %%i in (%SKINCONFITFILE%) do (
::		xcopy /Y %CURDIR%%IMAGEDIRNAME%_%%i\*.* %IMAGEDIR%
::		%QTDIR%\bin\rcc.exe -binary %QRCFILE% -o .\%QSSFILENAME%_%%i.rcc
::	)
::) ELSE (
::	%QTDIR%\bin\rcc.exe -binary %QRCFILE% -o .\%QSSFILENAME%.rcc
::)
::
::popd

%QTDIR%\bin\rcc.exe -binary %QRCFILE% -o .\%QSSFILENAME%.rcc