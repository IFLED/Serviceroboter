@echo off
rem --- SETTING VARIABLES ---------------------------------------
set dirForImageConverting="E:\Germany\EB\DBridge\Run"
set convertingBat="_start.bat"
set waveExe="C:\Program Files (x86)\TELEMED\Echo Wave II\EchoWave.exe"
set sharedDir=\\ifled-ub14\shared\project
rem set sharedDir=E:\Germany\IMAGES
set startFile=scan
set exitFile=stop
set timeWaiting=20
rem --- STARTING IMAGE CONVERTING PROGRAMM ----------------------
start "" /d %dirForImageConverting% %convertingBat%
rem --- STARTING ULTRASONICSCAN PROGRAMM ------------------------
start "" %waveExe%
timeout %timeWaiting%
rem --- CREATING STARTING FILE ----------------------------------
rem echo.>%sharedDir%\%startFile%
rem --- CHECKING LOOP -------------------------------------------
:loop
	if exist %sharedDir%\%exitFile% (
		del /F %sharedDir%\%exitFile%
		%waveExe% -exit
		echo END_OF_PROGRAMM
		pause
		exit
	)
	if exist %sharedDir%\%startFile% (
		del /Q %sharedDir%\Input\*
		%waveExe% -quicksave
		timeout 2
		rem ping 1.1.1.1 -n 1 -w 5000 > nul
		del /F %sharedDir%\%startFile%
		echo QUICKSAVED
	)
rem --- WAITING 0.1 sec -----------------------------------------
	ping 1.1.1.1 -n 1 -w 100 > nul
goto loop