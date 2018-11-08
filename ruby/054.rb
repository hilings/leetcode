# 054
# Spiral Matrix
# 2015-12-08
#####################################################
# @param {Integer[][]} matrix
# @return {Integer[]}
def spiral_order(matrix)
  $v = []
  return $v if matrix.size == 0
  push(matrix, 0, 0, matrix.size-1, matrix[0].size-1)
  $v
end

def push(matrix, a, b, c, d)
  return if (a > c || b > d)
  b.upto(d) do |i|
    $v.push(matrix[a][i])
  end
  (a+1).upto(c) do |i|
    $v.push(matrix[i][d])
  end
  return if (a == c || b == d)
  (d-1).downto(b) do |i|
    $v.push(matrix[c][i])
  end
  (c-1).downto(a+1) do |i|
    $v.push(matrix[i][b])
  end
  push(matrix, a+1, b+1, c-1, d-1);
end

#####################################################

matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

puts spiral_order(matrix)

