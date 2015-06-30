#   044
#   Wildcard Matching
#   2015-06-20
#####################################################
class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        l1 = len(s)
        l2 = len(p)
        if l1 < l2 - p.count('*'):
            return False

        m = [True] + [False] * l1
        for j in range(0, l2):
            if p[j] == '*':
                for i in range(1, l1+1):
                    m[i] = m[i-1] or m[i]
            else:
                for i in range(l1, 0, -1):
                    m[i] = m[i-1] and (s[i-1] == p[j] or p[j] == '?')
                m[0] = False

        return m[l1]

#####################################################

s = "abc"
p = "*ab*"


sol = Solution()
print sol.isMatch(s, p)   

