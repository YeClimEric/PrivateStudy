REM 环境初始化
set CURDIR=%~dp0%
set IMAGEDIRNAME=images
set QSSFILENAME=Skins
set IMAGEDIR=%CURDIR%%IMAGEDIRNAME%\
set QRCFILE=%CURDIR%%QSSFILENAME%.qrc
set QSSFILE=%CURDIR%%QSSFILENAME%.qss
set SKINCONFITFILE=%CURDIR%\SkinConfig.txt
set MULTISKIN=FALSE
::REM	开始读取皮肤配置文件
::if exist %SKINCONFITFILE% set MULTISKIN=TRUE
::REM 开始动态创建皮肤样式文件
::
::pushd %CURDIR%
::
::if "%MULTISKIN%" == "TRUE" (
::	REM 开始创建批复文件
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