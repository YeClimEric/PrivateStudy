REM 环境初始化
set CURDIR=%~dp0%
set IMAGEDIRNAME=images
set QSSFILENAME=Skins
set IMAGEDIR=%CURDIR%%IMAGEDIRNAME%\
set QRCFILE=%CURDIR%%QSSFILENAME%.qrc
set QSSFILE=%IMAGEDIR%%QSSFILENAME%.qss
set SKINCONFITFILE=%CURDIR%\SkinConfig.txt
set MULTISKIN=FALSE
set MODELIMAGE="/images/images"

REM	开始读取皮肤配置文件
::if exist %SKINCONFITFILE% set MULTISKIN=TRUE
REM 开始动态创建皮肤样式文件

for /f "tokens=1" %%i in (%CURDIR%images\Skins.qss) do(

)

pause