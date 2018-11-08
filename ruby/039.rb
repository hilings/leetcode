# 039
# Combination Sum
# 2015-05-16
#####################################################
# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
  candidates.sort!()
  solve(candidates, target, candidates.size-1)
end

def solve(candidates, target, limit)
  v = []
  return v if target < candidates.first
  v.push([target]) if candidates[0..limit].include?(target)
  for i in (0..limit)
    break if candidates[i] == target
    solve(candidates, target-candidates[i], i).each do |a|
      a.push(candidates[i])
      v.push(a)
    end
  end
  v
end

#####################################################

candidates = [2, 3, 6, 7]
target = 7

combination_sum(candidates, target).each do |a|
  puts a.inspect
end

