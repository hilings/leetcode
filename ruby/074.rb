#   074
#   Search a 2D Matrix
#   2016-01-02
#####################################################
# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
    m, n, i, j = matrix.size, matrix.first.size, 0, matrix.size-1
    while i < j
        mid = (i+j) / 2
        if target > matrix[mid][n-1]
            i = mid+1
        else
            j = mid
        end
    end
    row, i, j = i, 0, n-1
    while i <= j
        mid = (i+j)/2
        if target == matrix[row][mid]
            return true
        elsif target < matrix[row][mid]
            j = mid-1
        else
            i = mid+1
        end
    end
    false
end

#####################################################
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13

r = search_matrix(matrix, target)
puts r

