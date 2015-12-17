#   056
#   Merge Intervals
#   2015-12-13
#####################################################
# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []
        intervals.sort(key=lambda a: a.start)
        v = [intervals[0]]
        for a in intervals[1:]:
            if a.start <= v[-1].end:
                v[-1].end = max(v[-1].end, a.end)
            else:
                v.append(a)
        return v

#####################################################

intervals = [
    Interval(2,6),
    Interval(1,3),
    Interval(8,10),
    Interval(15,18)

    #Interval(1,4),
    #Interval(2,3)

    #Interval(2,3),
    #Interval(4,5),
    #Interval(6,7),
    #Interval(8,9),
    #Interval(1,10)

    #Interval(1,4),
    #Interval(0,2),
    #Interval(3,5)
]

sol = Solution()

for a in sol.merge(intervals):
    print a.start, a.end

