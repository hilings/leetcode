#   036
#   Valid Sudoku
#   2015-05-11
#####################################################
class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        for i in range(9):
            br = 0
            bc = 0
            bb = 0
            for j in range(9):
                c = board[i][j] # check row
                if c != '.':
                    d = ord(c) - ord('0')
                    if ((br >> d) & 1) == 1:
                        return False
                    else:
                        br |= 1<<d

                c = board[j][i] # check column
                if c != '.':
                    d = ord(c) - ord('0')
                    if ((bc >> d) & 1) == 1:
                        return False
                    else:
                        bc |= 1<<d

                c = board[i/3*3 + j/3][i%3*3 + j%3] # check block
                if c != '.':
                    d = ord(c) - ord('0')
                    if ((bb >> d) & 1) == 1:
                        return False
                    else:
                        bb |= 1<<d
        return True

#####################################################

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

sol = Solution()
print sol.isValidSudoku(board)

