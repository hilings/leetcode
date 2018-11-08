# 035
# Search Insert Position
# 2015-05-11
#####################################################
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)
  left = 0
  right = nums.size - 1
  while left < right
    mid = (left + right) / 2
    target <= nums[mid] ? right = mid : left = mid+1
  end
  target > nums[left] ? left + 1 : left
end

#####################################################

nums = [1, 3, 5, 6]
target = 0

puts search_insert(nums, target)

