//  067
//  Add Binary
//  2015-12-21
/////////////////////////////////////////////////////
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    if (a.length < b.length)
        return addBinary(b, a);
    var aa = a.split(''), i = a.length-1, j = b.length-1, c = 0;
    while (j >= 0) {
        var t = parseInt(a[i]) + parseInt(b[j]) + c;
        aa[i] = t % 2;
        c = Math.floor(t / 2);
        i--;
        j--;
    }
    while (i >= 0) {
        t = parseInt(a[i]) + c;
        aa[i] =  t % 2;
        c = Math.floor(t / 2);
        i--;
    }
    if (c == 1)
        aa.unshift('1');
    return aa.join('');
};

/////////////////////////////////////////////////////
var a = "111";
var b = "111";
var r = addBinary(a, b);
console.log(r);

