@echo off
echo ��� �⮣� bat 䠩��: %~n0
echo ���� � �⮬� bat 䠩��: %~dp0
echo ��� � �६� ᮧ�����:
for /f "tokens=1,2" %%a in ('dir Z03-02.bat /a-d /o-d /T:C') do @echo %%a %%b | find ":"
pause