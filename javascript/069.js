//  069
//  Sqrt(x)
//  2015-12-22
/////////////////////////////////////////////////////
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    var r = 1;
    while (r*r <= x)
        r = r << 1;
    var step = r >> 1;
    while (step > 0) {
        if ((r-step)*(r-step) > x)
            r -= step;
        step = step >> 1;
    }
    return r-1;
};

/////////////////////////////////////////////////////
var x = 2147483647;
var r = mySqrt(x);
console.log(r);
console.log(Math.floor(Math.sqrt(x)));

