//  070
//  Climbing Stairs
//  2015-12-23
/////////////////////////////////////////////////////
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n == 0)
        return 0;
    var last2 = 1;
    var last1 = 1;
    for (var i = 2; i <= n; i++) {
        var tmp = last1 + last2;
        last2 = last1;
        last1 = tmp;
    }
    return last1;
};

/////////////////////////////////////////////////////
var n = 4;
var r = climbStairs(n);
console.log(r);

