#   033
#   Search in Rotated Sorted Array
#   2015-05-11
#####################################################
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if target < nums[mid]:
                if (target >= nums[left]) ^ (nums[left] > nums[mid]):
                    right = mid-1
                else:
                    left = mid+1
            elif target > nums[mid]:
                if (target <= nums[right]) ^ (nums[mid] > nums[right]):
                    left = mid+1
                else:
                    right = mid-1
            else:
                return mid
        return -1

#####################################################

nums = [4, 5, 6, 7, 8, 0, 1, 2]
target = 5
sol = Solution()
z = sol.search(nums, target)
print(z)

