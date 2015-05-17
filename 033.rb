# 033
# Search in Rotated Sorted Array
# 2015-05-11
#####################################################
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
  left = 0
  right = nums.size - 1
  while left <= right
    mid = (left + right) / 2
    if target < nums[mid]
      (target >= nums[left]) ^ (nums[left] > nums[mid]) ? right = mid-1 : left = mid+1
    elsif target > nums[mid]
      (target <= nums[right]) ^ (nums[mid] > nums[right]) ? left = mid+1 : right = mid-1
    else
      return mid
    end
  end
  -1
end

#####################################################

nums = [4, 5, 6, 7, 0, 1, 2]
target = 5

puts search(nums, target)

