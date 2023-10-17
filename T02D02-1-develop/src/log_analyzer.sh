#!/bin/bash

echo "Введите название файла: "
read filename

if [ -f "$filename" ]; then
  count_unicum=0
  count_hashe=0
  
  arr_unicum=()
  arr_hashe=()
  
  all=$(wc -l "$filename" | awk '{print $1}')
  echo "Количество строк в файле $filename: $all"

  while read line; do
    unicum=$(echo "$line" | cut -d'/' -f2 | awk '{print $1}')
    hashe=$(echo "$line" | awk '{print$8}')
    
    if [[ "${arr_unicum[@]}" =~ "${unicum}" ]]; then
      :
    else
      arr_unicum+=("$unicum")
      ((count_unicum++))
    fi
    if [[ "$hashe" == "NULL" ]]
    then
    :
    else
    
    if [[ "${arr_hashe[@]}" =~ "${hashe}" ]]; then
      :
    else
      arr_hashe+=("$hashe")
      ((count_hashe++))
    fi
    fi
  done < "$filename"
  
  echo "Количество уникальных файлов в файле $filename: $count_unicum"
  echo "Количество уникальных хешей в файле $filename: $count_hashe"
  
else
  echo "Файл $filename не найден"
fi
