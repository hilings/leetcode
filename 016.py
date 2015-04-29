#   016
#   3Sum Closest
#   2015-04-22
#####################################################
class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        n = len(num)
        if n < 3:
            return 0
        num.sort()
        diff = 2147483647
        sum = 0
        for i in range(0, n-2):
            if i-1 >= 0 and num[i] == num[i-1]:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                t = num[i] +num[j] + num[k]
                d = abs(t - target)
                if d < diff:
                    diff = d
                    sum = t
                if t < target:
                    j += 1
                elif t >target:
                    k -= 1
                else:
                    return sum
        return sum

#####################################################
num = [-1, 2, 1, -4]
target = 1

sol = Solution()
print sol.threeSumClosest(num, target)

