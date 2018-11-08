#   060
#   Permutation Sequence
#   2015-12-16
#####################################################
import math
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        s = ""
        f = math.factorial(n)
        d = [str(i) for i in range(1, n+1)]
        for i in range(n, 0, -1):
            f //= i
            q = (k-1) // f
            s += d[q]
            del d[q]
            k -= q*f
        return s 

#####################################################
sol = Solution()

n = 3
k = 4

z = sol.getPermutation(n, k)
print(z)

