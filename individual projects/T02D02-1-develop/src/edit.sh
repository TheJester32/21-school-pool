while [$fileName == ""]
do read -p "Введите название файла, указав его формат и путь: " fileName
done

while [$STR1 == ""]
do read -p "Введите строку: " STR1
done

grep -q $STR1 $fileName

if grep -q $STR1 $fileName
then
    echo "Строка найдена"
    read -p "Введите новую строку: " STR2
    sed -i '' 's/'$STR1'/'$STR2'/g' t.txt
    echo '1...'
        echo '2...'
            echo '3...'
                        echo 'done!'
     
     size=$(wc -c $fileName | awk '{print $1}')
    _date=$(date -r $fileName "+%Y-%m-%d %H:%M")
     sha=$(shasum -a 256 $fileName | awk '{print $1}')
     
         echo "$fileName - $size - $_date - $sha - sha256" >> files.log
else
    echo 'Строка отсутсвует в этом файле'
fi



