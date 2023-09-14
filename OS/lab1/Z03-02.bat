@echo off
echo Имя этого bat файла: %~n0
echo Путь к этому bat файлу: %~dp0
echo Дата и время создания:
for /f "tokens=1,2" %%a in ('dir Z03-02.bat /a-d /o-d /T:C') do @echo %%a %%b | find ":"
pause