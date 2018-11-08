#   045
#   Jump Game II
#   2015-06-29
#####################################################
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        size = len(nums)
        v = [0] + [-1] * (size-1)
        for i in range(size):
            for j in range(min([size-1, i+nums[i]]), i, -1):
                if v[j] == -1 or v[i]+1 < v[j]:
                    v[j] = v[i]+1
                if j == size-1:
                    return v[j]
                if j+nums[j] >= size-1:
                    return v[j]+1
        return v[size-1]

#####################################################
nums = [2,3,1,1,4]

sol = Solution()
z = sol.jump(nums)
print(z)

