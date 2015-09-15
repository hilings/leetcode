#   048
#   Rotate Image
#   2015-09-04
#####################################################
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for row in range(n/2):
            for col in range((n+1)/2):
                tmp = matrix[row][col];
                matrix[row][col] = matrix[n-1-col][row];
                matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
                matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
                matrix[col][n-1-row] = tmp;

#####################################################
matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

print matrix

sol = Solution()
sol.rotate(matrix)

print matrix

