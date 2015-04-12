#   195
#   Tenth Line
#####################################################

echo -e "Line 1\nLine 2\nLine 3\nLine 4\nLine 5\nLine 6\nLine 7\nLine 8\nLine 9nLine 10" > file.txt

if [ `cat file.txt | wc -l` -ge 10 ]; then
    echo `cat file.txt | head -10 | tail -1`
else
    echo ''
fi

