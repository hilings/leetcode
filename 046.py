#   046
#   Permutations
#   2015-07-06

#####################################################
class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permute(self, nums):
        size = len(nums)
        v = [[nums[0]]]
        while len(v[0]) < size:
            a = v.pop(0)
            index = len(a)
            for i in range(index+1):
                c = list(a)
                c.insert(i, nums[index])
                v.append(c)
        return v

#####################################################

nums = [1,2,3]

sol = Solution()
print sol.permute(nums)

