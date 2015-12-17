#   059
#   Spiral Matrix II
#   2015-12-16
#####################################################
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        m = [[0]*n for i in range(n)]
        self.fill(m, 0, n-1, 0)
        return m

    def fill(self, m, p, q, count):
        if p > q:
            return
        elif p == q:
            count+=1
            m[p][p] = count
        for i in range(p, q):
            count += 1
            m[p][i] = count
        for i in range(p, q):
            count += 1
            m[i][q] = count
        for i in range(q, p, -1):
            count += 1
            m[q][i] = count
        for i in range(q, p, -1):
            count += 1
            m[i][p] = count
        self.fill(m, p+1, q-1, count)

#####################################################
sol = Solution()

n = 3
m = sol.generateMatrix(n)
for v in m:
    print v

