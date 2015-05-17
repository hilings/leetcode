#   038
#   Count and Say
#   2015-05-15
#####################################################
class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        s = "1"
        for i in range(1, n):
            print i, s
            tmp = ""
            count = 1
            j = 1
            l = len(s)
            while j < l:
                if s[j] == s[j-1]:
                    count += 1
                else:
                    tmp += str(count) + s[j-1]
                    count = 1
                j += 1
            tmp += str(count) + s[j-1]
            s = tmp
        print n, s
        return s

#####################################################

n = 5

sol = Solution()
sol.countAndSay(n)

