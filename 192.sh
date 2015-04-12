#   192
#   Word Frequency
#####################################################

printf "the day is sunny the the\nthe sunny is is\n" > words.txt

#IFS=' '
declare -A DICT

while read LINE; do
    STR=($LINE)
    for WORD in ${STR[@]}; do
        DICT[$WORD]=$((${DICT[$WORD]}+1))
        #echo "$WORD => ${DICT[$WORD]}"
    done
done<words.txt


for KEY in ${!DICT[@]}; do
    echo "${DICT[$KEY]} $KEY"
done | sort -nr | while read LINE; do
    STR=($LINE)
    echo ${STR[1]} ${STR[0]}
done


rm words.txt
