//  064
//  Minimum Path Sum
//  2015-12-17
/////////////////////////////////////////////////////
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var m = grid.length;
    var n = grid[0].length;
    var t = [grid[0][0]];
    for (var j = 1; j < n; j++) {
        t.push(t[j-1] + grid[0][j]);
    }
    console.log(t);

    for (var i = 1; i < m; i++) {
        t[0] = t[0] + grid[i][0];
        for (j = 1; j < n; j++) {
            t[j] = Math.min(t[j-1], t[j]) + grid[i][j];
        }
        console.log(t);
    }
    return t[n-1];
};

/////////////////////////////////////////////////////
var grid = [
    [1,2,3],
    [4,5,6]
];

var r = minPathSum(grid);
console.log(r);

