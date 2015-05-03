#   022
#   Generate Parentheses
#   2015-04-29
#####################################################
class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        v = []
        if n == 0:
            return v
        v.append("(")
        while len(v[0]) < 2*n:
            s = v.pop(0)
            l = r = 0
            for c in s:
                if c == '(':
                    l+=1
                else:
                    r+=1
            if l<n:
                v.append(s+"(")
            if l>r:
                v.append(s+")")
        return v

#####################################################

sol = Solution()
for n in range(0,9):
    v = sol.generateParenthesis(n)
    #print v
    print n, len(v)

