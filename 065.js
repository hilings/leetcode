//  065
//  Valid Number
//  2015-12-20
/////////////////////////////////////////////////////
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    var i = 0;
    var l = s.length;
    while (i < l && s[i] == ' ')
        i++;
    if (i == l)
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (myisdigit(s, i))
        i++;
    if (i < l && s[i] == '.') {
        if (!myisdigit(s, i-1) && !myisdigit(s, i+1))
            return false;
        i++;
    }
    while (myisdigit(s, i))
        i++;
    if (i < l && s[i] == 'e') {
        if (!myisdigit(s, i-1) && !myisdigit(s, i-2))
            return false;
        if (!myisdigit(s, i+1) && !myisdigit(s, i+2))
            return false;
        i++;
        if ((s[i] == '+' || s[i] == '-') && myisdigit(s, i+1))
            i++;
    }
    while (myisdigit(s, i))
        i++;
    while (i < l && s[i] == ' ')
        i++;
    return i == l;
};

function myisdigit(s, i) {
    if (i < 0 || i >= s.length || s[i] == ' ')
        return false;
    return !isNaN(s[i]);
}

/////////////////////////////////////////////////////
var s = " .";
var r = isNumber(s);
console.log(r);

