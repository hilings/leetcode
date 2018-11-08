#   006
#   ZigZag Conversion
#   2015-04-12
#####################################################
class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1:
            return s
        slen = len(s)
        str = ""
        for r in range(0, nRows):
            for i in range(r, slen, 2*nRows-2):
                str += s[i]
                if r != 0 and r != nRows-1:
                    t = i + 2*nRows - 2 - 2*r
                    if t < slen:
                        str += s[t]
        return str

#####################################################

s = "0123456789"
nRows = 4

print(s)
sol = Solution()
z = sol.convert(s, nRows)
print(z)

