#   051
#   N-Queens
#   2015-12-06
#####################################################
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        solutionset = []
        self.solve(solutionset, [], n, 0, 0, 0)
        return solutionset
    
    def solve(self, solutionset, solution, n, c, d1, d2):
        row = len(solution)
        if row == n:
            ts = []
            for i in solution:
                ts.append('.'*i + 'Q' + '.'*(n-1-i))
            solutionset.append(ts)
            return
        for col in range(0, n):
            if self.validate(solution, n, col, c, d1, d2):
                self.solve(solutionset, solution+[col], n, (1<<col)|c, (1<<(row-col+n))|d1, (1<<(row+col))|d2)
    
    def validate(self, solution, n, col, c, d1, d2):
        row = len(solution)
        if (1<<col)&c > 0 or (1<<(row-col+n))&d1 > 0 or (1<<(row+col))&d2 > 0:
            return False
        return True

#####################################################

sol = Solution()

print len(sol.solveNQueens(8))

