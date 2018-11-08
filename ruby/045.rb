# 045
# Jump Game II
# 2015-06-29
#####################################################
# @param {Integer[]} nums
# @return {Integer}
def jump(nums)
  size = nums.size
  v = [0] + [-1]*(size-1)
  0.upto(size-1) do |i|
    [size-1, i+nums[i]].min.downto(i+1) do |j|
      v[j] = v[i]+1 if v[j] == -1 or v[i]+1<v[j]
      return v[j] if j==size-1
      return v[j]+1 if j+nums[j] >= size-1
    end
  end
  v[size-1]
end

#####################################################
nums = [2,3,1,1,4]

puts jump(nums)

