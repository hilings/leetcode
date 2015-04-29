#   018
#   4Sum
#   2015-04-27
#####################################################
import collections
import itertools

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        v = []
        size = len(num)
        if size < 4:
            return v

        num.sort()
        for i in range(0, size-3):
            if i-1 >= 0 and num[i-1] == num[i]:
                continue
            for j in range(i+1, size-2):
                if j-1 >= i+1 and num[j-1] == num[j]:
                    continue
                p = j+1
                q = size-1
                while p < q:
                    if num[p]+num[q] < target-num[i]-num[j]:
                        p+=1
                    elif num[p]+num[q] > target-num[i]-num[j]:
                        q-=1
                    else:
                        t = [num[i], num[j], num[p], num[q]]
                        if t not in v:
                            v.append(t)
                        while p<q and num[p] == t[2]:
                            p+=1
                        while p<q and num[q] == t[3]:
                            q-=1
        return v

    def fourSum2(self, num, target):
        two_sum = collections.defaultdict(list)
        res = set()
        for (k1, v1), (k2, v2) in itertools.combinations(enumerate(num), 2):
            two_sum[v1+v2].append({k1, k2})
        for t in list(two_sum.keys()):
            if not two_sum[target-t]:
                continue
            for pair1 in two_sum[t]:
                for pair2 in two_sum[target-t]:
                    if pair1.isdisjoint(pair2):
                        res.add(tuple(sorted(num[i] for i in pair1 | pair2)))
            del two_sum[t]
        return [list(r) for r in res]

#####################################################

num = [1, 0, -1, 0, -2, 2]
target = 0

print num

sol = Solution()
print sol.fourSum2(num, target)

