# 053
# Maximum Subarray
# 2015-12-08
#####################################################
# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  tmp = nums[0]
  sum = nums[0]
  nums[1..-1].each do |a|
    tmp = [tmp+a, a].max
    sum = [sum, tmp].max
  end
  sum
end

#####################################################

nums = [-2,1,-3,4,-1,2,1,-5,4]

puts max_sub_array(nums)

