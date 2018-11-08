#   194. Transpose File
#   2016-03-22
#####################################################
echo "name age
alice 21
ryan 30" > file.txt

#####################################################
# Read from the file file.txt and print its transposed content to stdout.

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


#####################################################
# Read from the file file.txt and print its transposed content to stdout.

awk '{
    for (i = 1; i <= NF; i++) {
        if (word[i] == "") {
            word[i] = $i
        } else {
            word[i] = word[i]" "$i
        }
    }
} END {
    for (i = 1; i <= NF; i++) {
        print word[i]
    }
}' file.txt


#####################################################
# Read from the file file.txt and print its transposed content to stdout.

ncol=`head -n1 file.txt | wc -w`

for i in `seq 1 $ncol`
do
    echo `cut -d' ' -f$i file.txt`
done


#####################################################
#   cleanup

rm file.txt

