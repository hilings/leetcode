# 034
# Search for a Range
# 2015-05-11
#####################################################
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def search_range(nums, target)
  left = 0
  right = nums.size - 1
  while left < right
    mid = (left + right) / 2
    target <= nums[mid] ? right = mid : left = mid+1
  end
  if nums[left] == target
    v = [left]
  else
    return [-1, -1]
  end
  right = nums.size - 1
  while left < right
    mid = (left + right + 1) / 2
    target >= nums[mid] ? left = mid : right = mid-1
  end
  v.push(right)
end

#####################################################

nums = [5, 7, 7, 8, 8, 10]
target = 8
puts search_range(nums, target).inspect

