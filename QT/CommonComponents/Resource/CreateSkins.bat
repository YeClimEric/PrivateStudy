REM ������ʼ��
set CURDIR=%~dp0%
set IMAGEDIRNAME=images
set QSSFILENAME=Skins
set IMAGEDIR=%CURDIR%%IMAGEDIRNAME%\
set QRCFILE=%CURDIR%%QSSFILENAME%.qrc
set QSSFILE=%IMAGEDIR%%QSSFILENAME%.qss
set SKINCONFITFILE=%CURDIR%\SkinConfig.txt
set MULTISKIN=FALSE
set MODELIMAGE="/images/images"

REM	��ʼ��ȡƤ�������ļ�
::if exist %SKINCONFITFILE% set MULTISKIN=TRUE
REM ��ʼ��̬����Ƥ����ʽ�ļ�

for /f "tokens=1" %%i in (%CURDIR%images\Skins.qss) do(

)

pause