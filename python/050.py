#   050
#   Pow(x, n)
#   2015-09-14
#####################################################
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        if n < 0:
            x = 1/x
            n = -n
        result = 1
        while n > 0:
            result *= x if n&1>0 else 1
            x *= x
            n = n>>1
        return result

#####################################################

sol = Solution()
z = sol.myPow(2.5, 2)
print(z)

