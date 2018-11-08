# 041
# First Missing Positive
# 2015-05-18
#####################################################
# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
  n = nums.size
  i = 0
  while i < n
    if nums[i] > 0 and nums[i] <= n and nums[i]-1 != i
      nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
      i -= 1 if nums[i] > 0 and nums[i]-1 < i and nums[nums[i]-1] != nums[i]
    end
    i += 1
  end
  for i in (0...n)
    return i+1 if nums[i] != i+1
  end
  n+1
end

#####################################################

nums = [3, 4, -1, 1]
puts first_missing_positive(nums)

