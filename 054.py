#   054
#   Spiral Matrix
#   2015-12-09
#####################################################
class Solution(object):
    v = []
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        self.v = []
        if len(matrix) == 0:
            return self.v
        self.push(matrix, 0, 0, len(matrix)-1, len(matrix[0])-1)
        return self.v

    def push(self, matrix, a, b, c, d):
        if (a > c or b > d):
            return
        for i in range(b, d+1):
            self.v.append(matrix[a][i])
        for i in range(a+1, c+1):
            self.v.append(matrix[i][d])
        if (a == c or b == d):
            return
        for i in range(d-1, b-1, -1):
            self.v.append(matrix[c][i])
        for i in range(c-1, a, -1):
            self.v.append(matrix[i][b])
        self.push(matrix, a+1, b+1, c-1, d-1);

#####################################################

matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

sol = Solution()

print sol.spiralOrder(matrix)

