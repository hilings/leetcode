//  058
//  Length of Last Word
//  2015-12-15
/////////////////////////////////////////////////////
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var s2 = s.trim();
    return s2.length-1-s2.lastIndexOf(' ');
};

/////////////////////////////////////////////////////
var s = "  asdf asdf ";
console.log(lengthOfLastWord(s));

