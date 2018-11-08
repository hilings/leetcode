#   062
#   Unique Paths
#   2015-12-16
#####################################################
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        t = [1]*n
        for i in range(1, m):
            for j in range(1, n):
                t[j] += t[j-1]
        return t[n-1]
        
#####################################################
sol = Solution()

m = 3
n = 7
z = sol.uniquePaths(m, n)
print(z)

