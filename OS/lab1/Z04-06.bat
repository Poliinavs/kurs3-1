@echo off
echo ��ப� ��ࠬ��஢: %1  %2
echo �����: %1
echo ��� 䠩��: %2

if "%1"=="" (
    echo ०�� = {ᮧ����, 㤠����}
    echo 䠩� = ��� 䠩��
    goto exit
)

if "%2"=="" (
    echo ��� 䠩�� �� ������ 
    goto exit
)


if "%1" == "ᮧ����" (
    if exist %2 (
        echo 䠩� %2 㦥 �������
        goto exit
    )
    echo >  %2
    echo 䠩� %2 ᮧ���
    goto exit
)

if "%1" == "㤠����" (
    if not exist %2 (
        echo 䠩� %2 �� ������
        goto exit
    )
    del %2
    echo 䠩� %2 㤠���
    goto exit
)
  echo ०�� ��⠭����� �����४⭮


:exit
@pause
