#   063
#   Unique Paths II
#   2015-12-17
#####################################################
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        t = [1] + [0]*(n-1)
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                t[0] = 0
            for j in range(1, n):
                t[j] = 0 if obstacleGrid[i][j] == 1 else t[j-1]+t[j]
            #print
        return t[n-1]

#####################################################
sol = Solution()

obstacleGrid = [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

r = sol.uniquePathsWithObstacles(obstacleGrid)
print r

