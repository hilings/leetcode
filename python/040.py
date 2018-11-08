#   040
#   Combination Sum II
#   2015-05-16
#####################################################
class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum2(self, candidates, target):
        candidates.sort()
        return self.solve(candidates, target, len(candidates))

    def solve(self, candidates, target, limit):
        v = []
        if target < candidates[0]:
            return v
        for i in list(reversed(range(limit))):
            if (candidates[i] == target):
                v.append([target])
                limit = i
                break
        for i in list(reversed(range(limit))):
            if i < limit-1 and candidates[i] == candidates[i+1]:
                continue
            for a in self.solve(candidates, target-candidates[i], i):
                a.append(candidates[i])
                v.append(a)
        return v

#####################################################

candidates = [1,1,1,3,3,5]
target = 8

sol = Solution()
for a in sol.combinationSum2(candidates, target):
    print(a)

