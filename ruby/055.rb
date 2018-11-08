# 055
# Jump Game
# 2015-12-09
#####################################################
# @param {Integer[]} nums
# @return {Boolean}
def can_jump(nums)
  til = nums[0]
  i = 0
  while i <= til
    til = i+nums[i] if i+nums[i] > til
    return true if til >= nums.size-1
    i += 1
  end
  false
end

#####################################################

nums = [2,3,1,1,4]
nums = [3,2,1,0,4]

puts can_jump(nums)

