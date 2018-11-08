//  066
//  Plus One
//  2015-12-21
/////////////////////////////////////////////////////
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var c = 1;
    for (var i = digits.length-1; c == 1 && i >= 0; i--) {
        digits[i]++;
        c = digits[i] / 10;
        digits[i] %= 10;
    }
    if (c == 1)
        digits.unshift(1);
    return digits;
};

/////////////////////////////////////////////////////
var digits = [9, 9, 9];
var r = plusOne(digits);
console.log(r);

