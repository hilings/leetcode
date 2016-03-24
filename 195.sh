#   195. Tenth Line
#   2016-03-22
#####################################################
echo "Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
Line 11" > file.txt

#####################################################
# Read from the file file.txt and output the tenth line to stdout.

if [ `cat file.txt | wc -l` -ge 10 ]; then
    echo `cat file.txt | head -10 | tail -1`
else
    echo ''
fi


#####################################################
# Read from the file file.txt and output the tenth line to stdout.

awk 'FNR == 10 {print; exit}'  file.txt

# OR
awk 'NR == 10 {print; exit}' file.txt


#####################################################
# Read from the file file.txt and output the tenth line to stdout.

sed -n 10p file.txt


#####################################################
# Read from the file file.txt and output the tenth line to stdout.

tail -n+10 file.txt | head -1


#####################################################
#   cleanup

rm file.txt

