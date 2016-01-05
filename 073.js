//  073
//  Set Matrix Zeroes
//  2016-01-02
/////////////////////////////////////////////////////
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var m = matrix.length, n = matrix[0].length, row = false, col = false;
    for (var i = 0; i < m; i++) {
        for (var j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0)
                    row = true;
                if (j == 0)
                    col = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    if (row)
        for (j = 0; j < n; j++)
            matrix[0][j] = 0;
    if (col)
        for (i = 0; i < m; i++)
            matrix[i][0] = 0;
};

/////////////////////////////////////////////////////
var matrix = [
    [1,0,3],
    [4,5,6],
    [7,8,9]
];

setZeroes(matrix);

for (var i = 0; i < matrix.length; i++) {
    console.log(matrix[i]);
}

