#   029
#   Divide Two Integers
#   2015-05-04
#####################################################
class Solution:
    # @param {integer} dividend
    # @param {integer} divisor
    # @return {integer}
    def divide(self, dividend, divisor):
        if divisor == 0:
            return 0
        sign = (dividend > 0) ^ (divisor > 0)
        if dividend < 0:
            dividend = -dividend
        if divisor < 0:
            divisor = -divisor
        INT_MAX = 2147483647
        d = [divisor]
        i = 1
        while d[i-1] < dividend and d[i-1] < INT_MAX:
            d.append(d[i-1] + d[i-1])
            i+=1
        i -= 1
        res = 0
        while dividend >= divisor:
            while d[i] > dividend and i > 0:
                i -= 1
            r = 1
            for j in range(0, i):
                r += r
            res += r
            dividend -= d[i]
        if sign:
            res = -res
        return min(res, INT_MAX)

#####################################################

dividend = -2**31
divisor = -1
sol = Solution()
print "%d / %d = %d" % (dividend, divisor, sol.divide(dividend, divisor))

