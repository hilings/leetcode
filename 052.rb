# 052
# N-Queens II
# 2015-12-06
#####################################################
# @param {Integer} n
# @return {Integer}
def total_n_queens(n)
  $count = 0
  solve([], n, 0, 0, 0)
  $count
end

def solve(solution, n, c, d1, d2)
  row = solution.size
  if row == n
    $count += 1
    return
  end

  0.upto(n-1) do |col|
    solve(solution+[col], n, (1<<col)|c, (1<<(row-col+n))|d1, (1<<(row+col))|d2) if validate(solution, n, col, c, d1, d2)
  end
end

def validate(solution, n, col, c, d1, d2)
  row = solution.size
  return false if (1<<col)&c > 0 or (1<<(row-col+n))&d1 > 0 or (1<<(row+col))&d2 > 0
  true
end

#####################################################

puts total_n_queens(8)

