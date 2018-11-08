# 051
# N-Queens
# 2015-12-06
#####################################################
# @param {Integer} n
# @return {String[][]}
def solve_n_queens(n)
  solutionset = []
  solve(solutionset, [], n, 0, 0, 0)
  solutionset
end

def solve(solutionset, solution, n, c, d1, d2)
  row = solution.size
  if row == n
    ts = []
    solution.each do |i|
      ts << '.'*i + 'Q' + '.'*(n-1-i)
    end
    solutionset << ts
  end

  0.upto(n-1) do |col|
    solve(solutionset, solution+[col], n, (1<<col)|c, (1<<(row-col+n))|d1, (1<<(row+col))|d2) if validate(solution, n, col, c, d1, d2)
  end
end

def validate(solution, n, col, c, d1, d2)
  row = solution.size
  return false if (1<<col)&c > 0 or (1<<(row-col+n))&d1 > 0 or (1<<(row+col))&d2 > 0
  true
end

#####################################################

puts solve_n_queens(8).size

