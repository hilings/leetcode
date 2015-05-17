#   008
#   String to Integer (atoi)
#   2015-04-14
#####################################################
class Solution:
    # @param str, a string
    # @return an integer
    def myAtoi(self, str):
        s = str.strip()
        slen = len(s)
        i = 0
        sign = 1
        if i < slen and s[i] in ['+', '-']:
            sign = 1 if s[i] == '+' else -1
            i += 1
        z = 0
        while i < slen and s[i].isdigit() and z < 2147483647:
            z = z * 10 + int(s[i])
            i += 1
        if z > 2147483647:
            return 2147483647 if sign == 1 else -2147483648
        return sign * z

#####################################################

s = "\r-2147483649.1z"
print s

sol = Solution()
print sol.myAtoi(s)

