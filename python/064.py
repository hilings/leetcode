#   064
#   Minimum Path Sum
#   2015-12-17
#####################################################
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        t = [grid[0][0]]
        for j in range(1, n):
            t.append(t[j-1]+grid[0][j])
        print(t)

        for i in range(1, m):
            t[0] = t[0] + grid[i][0]
            for j in range(1, n):
                t[j] = min(t[j-1], t[j]) + grid[i][j]
            print(t)
        return t[n-1]

#####################################################
sol = Solution()

grid = [
    [1,2,3],
    [4,5,6]
]

z = sol.minPathSum(grid)
print(z)

