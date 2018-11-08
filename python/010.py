#   010
#   Regular Expression Matching
#   2015-04-18
#####################################################
class Solution:
    # @param s, a string
    # @param p, a string
    # @return a boolean
    def isMatch(self, s, p):
        l1 = len(s)
        l2 = len(p)

        i = 0
        j = 0
        while i < l1 and j < l2:
            if j+1 < l2 and p[j+1] == '*':
                if s[i] != p[j] and p[j] != '.':
                    j+=2
                elif self.isMatch(s[i:], p[j+2:]):
                    return True
                elif s[i] == p[j] or p[j] == '.':
                    i+=1
                else:
                    return False
            elif s[i] == p[j] or p[j] == '.':
                i+=1
                j+=1
            else:
                return False
        if i < l1:
            return False
        while j < l2 :
            if j+1 < l2 and p[j+1] == '*':
                j+=2
        return j == l2

#####################################################
    # @param s, a string
    # @param p, a string
    # @return a boolean
    def isMatch2(self, s, p):
        l1 = len(s)
        l2 = len(p)
        m = [True] + [False] * l1
        for j in range(0, l2):
            if j+1 < l2 and p[j+1] == '*':
                continue
            elif p[j] == '*':
                c = p[j-1]
                for i in range(1, l1+1):
                    m[i] = m[i] or (m[i-1] and (s[i-1] == c or c == '.'))
            else:
                c = p[j]
                for i in range(l1, 0, -1):
                    m[i] = m[i-1] and (m[i-1] and (s[i-1] == c or c == '.'))
                m[0] = False
        return m[l1]

#####################################################

s = "aaa";
p = "a*a";
s = "ab";
p = ".*..c*";
s = "baccbbcbcacacbbc";
p = "c*.*b*c*ba*b*b*.a*";
s = "aaa"
p = "aaaa"

print(s)
print(p)

sol = Solution()
z = sol.isMatch2(s, p)
print(z)

