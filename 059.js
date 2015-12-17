//  059
//  Spiral Matrix II
//  2015-12-16
/////////////////////////////////////////////////////
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    var m = [];
    for (var i = 0; i < n; i++) {
        m[i] = new Array(n);
    }
    fill(m, 0, n-1, 0);
    return m;
};

function fill(m, p, q, count) {
    if (p == q) {
        m[p][p] = ++count;
        return;
    }
    else if (p > q) {
        return;
    }
    for (var i = p; i < q; i++) {
        m[p][i] = ++count;
    }
    for (i = p; i < q; i++) {
        m[i][q] = ++count;
    }
    for (i = q; i > p; i--) {
        m[q][i] = ++count;
    }
    for (i = q; i > p; i--) {
        m[i][p] = ++count;
    }
    fill(m, p+1, q-1, count);
}

/////////////////////////////////////////////////////
var n = 3;
var m = generateMatrix(n);
for (var i = 0; i < n; i++) {
    console.log(m[i]);
}

