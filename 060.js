//  060
//  Permutation Sequence
//  2015-12-16
/////////////////////////////////////////////////////
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    var s = "";
    var f = 1;
    var d = [];
    for (var i = 1; i <= n; i++) {
        f *= i;
        d.push(i);
    }
    for (i = n; i > 0; i--) {
        f /= i;
        var q = Math.floor((k-1) / f);
        s += d[q];
        d.splice(q, 1);
        k -= q*f;
    }
    return s;
};

/////////////////////////////////////////////////////
var n = 3;
var k = 4;
console.log(getPermutation(n, k));

