#   013
#   Roman to Integer
#   2015-04-20
#####################################################
class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        n = [  1,   5,  10,  50, 100, 500, 1000]
        c = ['I', 'V', 'X', 'L', 'C', 'D', 'M' ]
        
        num = 0
        nlen = len(n)
        i = nlen - 1
        slen = len(s)
        p = 0
        while p < slen:
            if i+2 < nlen and s[p] == c[i+2]:
                num = num - n[i]*2 + n[i+2]
                i-=1
                p+=1
            elif i+1 < nlen and s[p] == c[i+1]:
                num = num - n[i]*2 + n[i+1]
                i-=1
                p+=1
            elif s[p] == c[i]:
                num += n[i]
                p+=1
            else:
                i-=1
        return num

#####################################################

s = "IX"
print(s)
sol = Solution()
z = sol.romanToInt(s)
print(z)

