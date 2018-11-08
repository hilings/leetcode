#   039
#   Combination Sum
#   2015-05-16
#####################################################
class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):
        candidates.sort()
        return self.solve(candidates, target, len(candidates)-1)

    def solve(self, candidates, target, limit):
        v = []
        if target < candidates[0]:
            return v
        if target in candidates[:limit+1]:
            v.append([target])
        for i in range(limit+1):
            if target == candidates[i]:
                break
            for a in self.solve(candidates, target-candidates[i], i):
                a.append(candidates[i])
                v.append(a)
        return v

#####################################################

candidates = [3, 2, 1]
target = 6

sol = Solution()
for a in sol.combinationSum(candidates, target):
    print(a)

