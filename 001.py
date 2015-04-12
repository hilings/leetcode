#   001
#   Two Sum
#####################################################

class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        b = sorted(num)
        i = 0
        j = len(b) - 1

        while i < j:
            if b[i] + b[j] < target:
                i += 1
            elif b[i] + b[j] > target:
                j -= 1
            else:
                index1 = num.index(b[i])
                index2 = len(num) - num[::-1].index(b[j]) - 1
                if index1 < index2:
                    return (index1 + 1, index2 + 1)
                else:
                    return (index2 + 1, index1 + 1)

#####################################################

numbers = [-1, -2, -3, -4, -5]
numbers = [3, 2, 4]
numbers = [3, 2, 5, 3]
target = 6

sol = Solution()
print sol.twoSum(numbers, target)

