#   031
#   Next Permutation
#   2015-05-10
#####################################################
class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def nextPermutation(self, nums):
        n = len(nums)
        if n <= 1:
            return
        i = n - 2
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        if i >= 0:
            b = min([a for a in nums[i+1:] if a > nums[i]])
            index = i+1 + nums[i+1:].index(b)
            nums[i], nums[index] = nums[index], nums[i]
        nums[i+1:] = sorted(nums[i+1:])
        return

#####################################################

nums = [5,4,7,5,3,2]
print nums

sol = Solution()
for i in range(6):
    sol.nextPermutation(nums)
    print nums

