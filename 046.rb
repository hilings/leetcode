# 046
# Permutations
# 2015-07-02
#####################################################
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  v = [[nums.first]]
  while v.first.size < nums.size
    a = v.shift
    l = a.size
    0.upto(l) do |i|
      next if i < l and a[i] == nums[l]
      v.push(Array.new(a).insert(i, nums[l]))
    end
  end
  v
end

#####################################################

nums = [1,2,3]
puts nums.inspect
puts permute(nums).inspect

