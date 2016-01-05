#   074
#   Search a 2D Matrix
#   2016-01-02
#####################################################
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m, n, i, j = len(matrix), len(matrix[0]), 0, len(matrix)-1
        while i < j:
            mid = (i+j) / 2
            if target > matrix[mid][n-1]:
                i = mid+1
            else:
                j = mid
        row, i, j = i, 0, n-1
        while i <= j:
            mid = (i+j)/2
            if target == matrix[row][mid]:
                return True
            elif target < matrix[row][mid]:
                j = mid-1
            else:
                i = mid+1
        return False
        
#####################################################
sol = Solution()

matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 11

r = sol.searchMatrix(matrix, target)
print r 

