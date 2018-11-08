# 040
# Combination Sum II
# 2015-05-16
#####################################################
# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum2(candidates, target)
  candidates.sort!()
  solve(candidates, target, candidates.size)
end

def solve(candidates, target, limit)
  v = []
  return v if target < candidates.first
  (limit-1).downto(0) do |i|
    if candidates[i] == target
      v.push([target])
      limit = i
      break
    end
  end
  (limit-1).downto(0) do |i|
    next if i < limit-1 and candidates[i] == candidates[i+1]
    solve(candidates, target-candidates[i], i).each do |a|
      a.push(candidates[i])
      v.push(a)
    end
  end
  v
end

#####################################################

candidates = [1,1,1,3,3,5]
target = 8

candidates = [2,5,2,1,2]
target = 5

combination_sum2(candidates, target).each do |a|
  puts a.inspect
end

