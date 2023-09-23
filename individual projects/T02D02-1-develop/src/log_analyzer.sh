read -p "Введите название файла, указав его формат и путь: " filePath
if [ "$filePath" == "" ]; then
echo "Файл отсутсвует"
exit
fi

correctLog=${filePath##*.}

if [ "$correctLog" != "log" ]; then
echo "Тип указан неверно"
exit
fi

if [ -f $filePath ]; then
strings=$(wc -l $filePath | awk '{print $1}')
newStrings=$(awk '{print $1}' $filePath | sort | uniq | wc -l | awk '{print $1}')
difference=$(($strings - $newStrings))

echo "$strings $newStrings $difference"

else
echo "Файл не найден"
fi
