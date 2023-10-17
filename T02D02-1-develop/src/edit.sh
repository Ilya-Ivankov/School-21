#!/bin/bash

echo "Введите путь до файла:"
read file_path

echo "Введите строку для замены:"
read search_string
echo "Введите строку замены:"
read replace_string

if [ -f "$file_path" ]
then
    if [["$search_string" == "" || "$search_string" == "$replace_string"]]
    then
        echo "Данные не корректны - замена не выполнена"
    else
        sed -i "" "s/$search_string/$replace_string/g" "$file_path"
        echo "Строка '$search_string' успешно заменена на '$replace_string' в файле $file_path"
        
        
        
        echo "src/$file_path - "$(stat -f %z "$file_path")" - $(date +"%Y-%m-%d %H:%m") - $(shasum -a 256 "$file_path" | awk '{print$1}') - sha256" >> files.log

    fi
else
  echo "Файл $file_path не найден"
fi
