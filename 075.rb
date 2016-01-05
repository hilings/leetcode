# 075
# Sort Colors
# 2016-01-04
#####################################################
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def sort_colors(nums)
  i, j = 0, nums.size-1
  while i < j
    i+=1 while i < nums.size and nums[i] == 0
    j-=1 while j >= 0 and nums[j] >= 1
    nums[i], nums[j] = nums[j], nums[i] if i < j
  end
  j = nums.size-1
  while i < j
    i+=1 while i < nums.size and nums[i] == 1
    j-=1 while j >= 0 and nums[j] == 2
    nums[i], nums[j] = nums[j], nums[i] if i < j
  end
end

def sort_colors2(nums)
  i, zero, two = 0, 0, nums.size-1
  while i <= two
    if nums[i] == 0
      nums[i], nums[zero] = nums[zero], nums[i]
      i, zero = i+1, zero+1
    elsif nums[i] == 2
      nums[i], nums[two] = nums[two], nums[i]
      two-=1
    else
      i+=1
    end
  end
end

#####################################################
nums = [2,1,0,2,0,2,1,0,2]

sort_colors(nums)

print nums

