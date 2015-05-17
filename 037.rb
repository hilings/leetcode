# 037
# Sudoku Solver
# 2015-05-14
#####################################################
# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
$candidate = []
def solve_sudoku(board)
  printBoard(board)
  for co in (0...81)
    $candidate[co] = []
    if board[co/9][co%9] == '.'
      for k in (1..9)
        if isValid(board, co, k.to_s)
          $candidate[co] << k
        end
      end
    end
    puts "#{co/9} #{co%9} -> #{$candidate[co].inspect}" if not $candidate[co].empty?
  end

  u = uniqueCandidate()
  while u > -1
    i = u / 9
    j = u % 9
    d = $candidate[u].first
    board[i][j] = d.to_s
    for k in (0...9)
      $candidate[9*i+k].delete(d)
      $candidate[9*k+j].delete(d)
      $candidate[9*(i/3*3+k/3)+j/3*3+k%3].delete(d)
    end
    u = uniqueCandidate()
  end
  for co in (0...81)
    puts "#{co/9} #{co%9} -> #{$candidate[co].inspect}" if not $candidate[co].empty?
  end

  solve(board, 0)
  printBoard(board)
  return
end
def solve(board, co)
  return true if co == 81
  i = co / 9
  j = co % 9
  return solve(board, co+1) if board[i][j] != '.'
  for k in (1..9)
    if isValid(board, co, k.to_s)
      board[i][j] = k.to_s
      if solve(board, co+1)
        return true
      else
        board[i][j] = '.'
      end
    end
  end
  false
end
def isValid(board, co, value)
  i = co / 9
  j = co % 9
  for k in (0...9)
    return false if (board[i][k] == value or board[k][j] == value or board[i/3*3+k/3][j/3*3+k%3] == value)
  end
  true
end
def uniqueCandidate()
  for co in (0...81)
    return co if $candidate[co].size == 1
  end
  -1
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

solve_sudoku(board)

