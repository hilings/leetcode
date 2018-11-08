#   192. Word Frequency
#   2016-03-21
#####################################################
echo "the day is sunny the the
the sunny is is" > words.txt

#####################################################
# Read from the file words.txt and output the word frequency list to stdout.
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


#####################################################
# Read from the file words.txt and output the word frequency list to stdout.

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}'


#####################################################
#   cleanup

rm words.txt

