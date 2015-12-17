#   057
#   Insert Interval
#   2015-12-15
#####################################################
# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        index_start = len(intervals)
        index_end = len(intervals)-1
        for i, a in enumerate(intervals):
            if newInterval.start <= a.end:
                index_start = i
                newInterval.start = min(newInterval.start, a.start)
                break
        for i, a in enumerate(intervals[index_start:]):
            if newInterval.end < a.start:
                index_end = index_start+i-1
                break
            elif newInterval.end <= a.end:
                index_end = index_start+i
                newInterval.end = a.end
                break
        return intervals[0:index_start]+[newInterval]+intervals[index_end+1:]

#####################################################
sol = Solution()

intervals = [
    Interval(1,3),
    Interval(6,9)
]
newInterval = Interval(2,8)

r = sol.insert(intervals, newInterval)
for a in r:
    print a.start, a.end

