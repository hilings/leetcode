#   037
#   Sudoku Solver
#   2015-05-14
#####################################################
import math
class Solution:
    candidate = []
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solveSudoku(self, board):
        printBoard(board)

        for co in range(81):
            i = co // 9
            j = co % 9
            self.candidate.append(0)
            if board[i][j] == '.':
                for k in range(1, 10):
                    if self.isValid(board, co, chr(ord('0')+k)):
                        self.candidate[co] |= 1<<k
            if self.candidate[co]:
                print(i, j, self.candidate[co])

        u = self.uniqueCandidate(board)
        while u > -1:
            i = u // 9
            j = u % 9
            d = int(math.log(self.candidate[u], 2))
            board[i][j] = chr(ord('0')+d)
            print(i, j, " <- ", d)
            for k in range(9):
                self.candidate[9*i+k] &= ~(1<<d)
                self.candidate[9*k+j] &= ~(1<<d)
                self.candidate[9*(i//3*3+k//3)+j//3*3+k%3] &= ~(1<<d)
            u = self.uniqueCandidate(board)
        print()
        for co in range(81):
            if self.candidate[co]:
                print(co//9, co%9, self.candidate[co])

        self.solve(board, 0)
        printBoard(board)
        return
    def solve(self, board, co):
        if co == 81:
            return True
        i = co // 9
        j = co % 9
        if board[i][j] != '.':
            return self.solve(board, co+1)
        for k in range(1, 10):
            if self.isValid(board, co, chr(ord('0')+k)):
                board[i][j] = chr(ord('0')+k)
                if self.solve(board, co+1):
                    return True
                board[i][j] = '.'
        return False
    def isValid(self, board, co, c):
        i = co // 9
        j = co % 9
        for k in range(9):
            if board[i][k] == c or board[k][j] == c or board[i//3*3+k//3][j//3*3+k%3] == c:
                return False
        return True
    def uniqueCandidate(self, board):
        for co in range(81):
            if self.candidate[co] in [2, 4, 8, 16, 32, 64, 128, 256, 512]:
                return co
        return -1



def printBoard(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end='')
            if j % 3 == 2:
                print(' ', end='')
        print()
        if i % 3 == 2:
            print()

#####################################################

board = [
"..9748...",
"7........",
".2.1.9...",
"..7...24.",
".64.1.59.",
".98...3..",
"...8.3.2.",
"........6",
"...2759.."
]

board = [
"53..7....",
"6..195...",
".98....6.",
"8...6...3",
"4..8.3..1",
"7...2...6",
".6....28.",
"...419..5",
"....8..79"
]

for i in range(9):
    board[i] = list(board[i])

sol = Solution()
sol.solveSudoku(board)

