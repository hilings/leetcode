//  063
//  Unique Paths II
//  2015-12-17
/////////////////////////////////////////////////////
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var m = obstacleGrid.length;
    var n = obstacleGrid[0].length;
    var t = [1];
    for (var j = 1; j < n; j++) {
        t.push(0);
    }
    for (var i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            t[0] = 0;
        for (j = 1; j < n; j++) {
            t[j] = obstacleGrid[i][j] == 1 ? 0 : t[j-1]+t[j];
        }
        console.log(t);
    }
    return t[n-1];
};

/////////////////////////////////////////////////////
var obstacleGrid = [
    [0,0,0],
    [0,1,0],
    [0,0,0]
];

var r = uniquePathsWithObstacles(obstacleGrid);

console.log(r);

