#   194
#   Transpose File
#####################################################

printf "name age\nalice 21\nyan 30\n" > file.txt

#IFS=' '
#declare -A MATRIX

while read LINE; do
    STR=($LINE)
    COL=0
    for WORD in ${STR[@]}; do
        COL=$(($COL+1))
        MATRIX[$COL]+=" $WORD"
    done
done<file.txt


for KEY in ${!MATRIX[@]}; do
    echo ${MATRIX[$KEY]}
done


rm file.txt
