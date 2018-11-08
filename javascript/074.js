//  074
//  Search a 2D Matrix
//  2016-01-02
/////////////////////////////////////////////////////
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var m = matrix.length, n = matrix[0].length, i = 0, j = matrix.length-1;
    while (i < j) {
        var mid = Math.floor((i+j)/2);
        if (target > matrix[mid][n-1])
            i = mid+1;
        else
            j = mid;
    }
    var row = i; i = 0; j = n-1;
    while (i <= j) {
        mid = Math.floor((i+j)/2);
        if (target == matrix[row][mid])
            return true;
        else if (target < matrix[row][mid])
            j = mid-1;
        else
            i = mid+1;
    }
    return false;    
};

/////////////////////////////////////////////////////
var matrix = [
  [ 1,  3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
];
var target = 12;

var r = searchMatrix(matrix, target);
console.log(r);

