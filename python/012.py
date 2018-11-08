#   012
#   Integer to Roman
#   2015-04-20
#####################################################
class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        n = [  1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000]
        c = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" ]
        str = ""
        i = len(n) - 1
        while num > 0:
            if num < n[i]:
                i -= 1
                continue
            str += c[i]
            num -= n[i]
        return str

#####################################################

sol = Solution();

for i in range(0, 15):
    print(i, sol.intToRoman(i))

