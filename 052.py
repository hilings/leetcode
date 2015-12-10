#   052
#   N-Queens II
#   2015-12-07
#####################################################
class Solution(object):
    count = 0
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.count = 0
        self.solve([], n, 0, 0, 0)
        return self.count
    
    def solve(self, solution, n, c, d1, d2):
        row = len(solution)
        if row == n:
            self.count += 1
            return
        for col in range(0, n):
            if self.validate(solution, n, col, c, d1, d2):
                self.solve(solution+[col], n, (1<<col)|c, (1<<(row-col+n))|d1, (1<<(row+col))|d2)
    
    def validate(self, solution, n, col, c, d1, d2):
        row = len(solution)
        if (1<<col)&c > 0 or (1<<(row-col+n))&d1 > 0 or (1<<(row+col))&d2 > 0:
            return False
        return True

#####################################################

sol = Solution()

print sol.totalNQueens(8)

