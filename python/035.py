#   035
#   Search Insert Position
#   2015-05-11
#####################################################
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if target <= nums[mid]:
                right = mid
            else:
                left = mid+1
        if target > nums[left]:
            return left+1
        else:
            return left

#####################################################

nums = [1, 3, 5, 6]
target = 7

sol = Solution()
z = sol.searchInsert(nums, target)
print(z)

