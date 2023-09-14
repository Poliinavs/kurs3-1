@echo off
echo Строка параметров: %1  %2
echo Режим: %1
echo Имя файла: %2

if "%1"=="" (
    echo режим = {создать, удалить}
    echo файл = имя файла
    goto exit
)

if "%2"=="" (
    echo имя файла не задано 
    goto exit
)


if "%1" == "создать" (
    if exist %2 (
        echo файл %2 уже существует
        goto exit
    )
    echo >  %2
    echo файл %2 создан
    goto exit
)

if "%1" == "удалить" (
    if not exist %2 (
        echo файл %2 не найден
        goto exit
    )
    del %2
    echo файл %2 удален
    goto exit
)
  echo режим установлен некорректно


:exit
@pause
