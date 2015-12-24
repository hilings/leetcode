#   070
#   Climbing Stairs
#   2015-12-23
#####################################################
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        last2, last1 = 1, 1
        for i in range(2, n+1):
            last2, last1 = last1, last1+last2
        return last1

#####################################################
sol = Solution()
n = 4
r = sol.climbStairs(n)
print r

