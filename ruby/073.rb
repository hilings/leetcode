#   073
#   Set Matrix Zeroes
#   2016-01-02
#####################################################
# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def set_zeroes(matrix)
    m, n, row, col = matrix.size, matrix.first.size, false, false
    (0...m).each do |i|
        (0...n).each do |j|
            if matrix[i][j] == 0
                row = true if i == 0
                col = true if j == 0
                matrix[i][0] = 0
                matrix[0][j] = 0
            end
        end
    end
    (1...m).each do |i|
        (1...n).each do |j|
            matrix[i][j] = 0 if matrix[i][0] == 0 or matrix[0][j] == 0
        end
    end
    (0...n).each { |j| matrix[0][j] = 0 } if row
    (0...m).each { |i| matrix[i][0] = 0 } if col
end

#####################################################
matrix = [
    [1,0,3],
    [4,5,6],
    [7,8,9]
]
set_zeroes(matrix)
matrix.each do |v|
    print v
    puts
end

