#   193. Valid Phone Numbers
#   2016-03-21
#####################################################
echo "987-123-4567
123 456 7890
(123) 456-7890" > file.txt

#####################################################
# Read from the file file.txt and output all valid phone numbers to stdout.

while read LINE; do [[ $LINE =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]] || [[ $LINE =~ ^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]] && echo $LINE; done<file.txt


#####################################################
# Read from the file file.txt and output all valid phone numbers to stdout.
#   grep
#   -P, --perl-regexp
#   -E, --extended-regexp, for Mac OSX

#grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
grep -E '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt


#####################################################
# Read from the file file.txt and output all valid phone numbers to stdout.
#   sed
#   -n, --quiet, --silent
#   -r, --regexp-extended
#   -E, regular expressions for Max OSX

#sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt


#####################################################
# Read from the file file.txt and output all valid phone numbers to stdout.
#   awk

#cat file.txt | awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p'

awk '/^([0-9][0-9][0-9]-|\([0-9][0-9][0-9]\) )[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$/' file.txt


#####################################################
#   cleanup

rm file.txt

