# 031
# Next Permutation
# 2015-05-10
#####################################################
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def next_permutation(nums)
  n = nums.size
  return if n <= 1
  i = n - 2
  while i >= 0 and nums[i] >= nums[i+1]
    i-=1
  end
  if i >= 0
    index = nums.each_with_index.find_all{|value, index| index > i and value > nums[i]}.min[1]
    nums[i], nums[index] = nums[index], nums[i]
  end
  nums[i+1..-1] = nums[i+1..-1].sort
end

#####################################################

nums = [1,2]
puts nums.inspect

(1..6).each do 
  next_permutation(nums)
  puts nums.inspect
end

