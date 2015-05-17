# 036
# Valid Sudoku
# 2015-05-11
#####################################################
# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)
  set1 = []
  set2 = []
  set3 = []
  for i in (0...9)
    set1.clear()
    set2.clear()
    set3.clear()
    for j in (0...9)
      c = board[i][j] # check row
      if c != '.'
        return false if set1.include?(c)
        set1.push(c)
      end
      c = board[j][i] # check column
      if c != '.'
        return false if set2.include?(c)
        set2.push(c)
      end
      c = board[i/3*3 + j/3][i%3*3 + j%3] # check block
      if c != '.'
        return false if set3.include?(c)
        set3.push(c)
      end
    end
  end
  true
end

def printBoard(board)
  for i in (0...board.size())
    for j in (0...board.size())
      print board[i][j]
      print '  ' if j % 3 == 2
    end
    print "\n"
    print "\n" if i % 3 == 2
  end
end

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

printBoard(board)

puts is_valid_sudoku(board)

