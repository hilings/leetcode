# 047
# Permutations II
# 2015-09-04
#####################################################
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def next_permutation(nums)
  n = nums.size
  return false if n <= 1
  i = n - 2
  while i >= 0 and nums[i] >= nums[i+1]
    i-=1
  end
  if i >= 0
    index = nums.each_with_index.find_all{|value, index| index > i and value > nums[i]}.min[1]
    nums[i], nums[index] = nums[index], nums[i]
  end
  nums[i+1..-1] = nums[i+1..-1].sort
  return i >= 0
end

# @param {Integer[]} nums
# @return {Integer[][]}
def permute_unique(nums)
  nums.sort!
  v = [nums]
  while next_permutation(nums)
    v.push(nums.dup)
  end
  v
end

#####################################################

nums = [1,2,3]
v = permute_unique(nums)
puts v.inspect

