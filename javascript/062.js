//  062
//  Unique Paths
//  2015-12-16
/////////////////////////////////////////////////////
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var t = [];
    for (var i = 0; i < n; i++) {
        t.push(1);
    }
    for (i = 1; i < m; i++) {
        for (var j = 1; j < n; j++) {
            t[j] += t[j-1];
        }
    }
    return t[n-1];
};

/////////////////////////////////////////////////////
var m = 3;
var n = 7;
var r = uniquePaths(m, n);
console.log(r);

