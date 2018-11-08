#   034
#   Search for a Range
#   2015-05-11
#####################################################
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def searchRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if target <= nums[mid]:
                right = mid
            else:
                left = mid+1
        if nums[left] == target:
            v = [left]
        else:
            return [-1, -1]
        right = len(nums) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if target >= nums[mid]:
                left = mid
            else:
                right = mid-1
        v.append(right)
        return v

#####################################################

nums = [5, 7, 7, 8, 8, 10]
target = 8

sol = Solution()
z = sol.searchRange(nums, target)
print(z)

