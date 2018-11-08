#   073
#   Set Matrix Zeroes
#   2016-01-02
#####################################################
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n, row, col = len(matrix), len(matrix[0]), False, False
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    if i == 0:
                        row = True
                    if j == 0:
                        col = True
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if row:
            for j in range(n):
                matrix[0][j] = 0
        if col:
            for i in range(m):
                matrix[i][0] = 0

#####################################################
sol = Solution()

matrix = [
    [1,0,3],
    [4,5,6],
    [7,8,9]
]
sol.setZeroes(matrix)
for v in matrix:
    print(v)

