#   007
#   Reverse Integer
#   2015-04-12
#####################################################
class Solution:
    # @return an integer
    def reverse(self, x):
        if x < 0:
            return -self.reverse(-x)
        z = 0
        while x != 0:
            z = z * 10 + x % 10
            x /= 10
        if z > 2147483647 or z < -2147483648:
            return 0
        return z

#####################################################

x = 1534236469
print x

sol = Solution()
print sol.reverse(x)


