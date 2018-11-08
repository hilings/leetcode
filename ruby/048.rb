# 048
# Rotate Image
# 2015-09-04
#####################################################
# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def rotate(matrix)
  n = matrix.size
  (0...n/2).each do |row|
    (0...(n+1)/2).each do |col|
      tmp = matrix[row][col];
      matrix[row][col] = matrix[n-1-col][row];
      matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
      matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
      matrix[col][n-1-row] = tmp;
    end
  end
  return 
end

#####################################################

matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

puts matrix.inspect

rotate(matrix)

puts matrix.inspect

