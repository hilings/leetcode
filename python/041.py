#   041
#   First Missing Positive
#   2015-05-18
#####################################################
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def firstMissingPositive(self, nums):
        n = len(nums)
        i = 0
        while i < n:
            if nums[i] > 0 and nums[i] <= n and nums[i]-1 != i:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
                if nums[i] > 0 and nums[i]-1 < i and nums[nums[i]-1] != nums[i]:
                    i -= 1
            i += 1
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1
        
#####################################################

nums = [3, 4, -1, 1]
nums = [-10,-3,-100,-1000,-239,1]
sol = Solution()
z = sol.firstMissingPositive(nums)
print(z)

