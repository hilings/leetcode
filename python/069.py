#   069
#   Sqrt(x)
#   2015-12-22
#####################################################
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = 1
        while r*r <= x:
            r = r << 1
        step = r >> 1
        while step > 0:
            if (r-step)*(r-step) > x:
                r -= step
            step = step >> 1
        return r-1
        
#####################################################
sol = Solution()
x = 2147483647
r = sol.mySqrt(x)
print(r)

import math
print(int(math.sqrt(x)))

