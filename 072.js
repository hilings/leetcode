//  072
//  Edit Distance
//  2016-01-01
/////////////////////////////////////////////////////
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    var l1 = word1.length;
    var l2 = word2.length;
    if (l1 == 0 || l2 == 0)
        return l1 + l2;
    var d = new Array(l1);
    for (var i = 0; i < l1; i++)
        d[i] = new Array(l2);
    d[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (i = 1; i < l1; i++)
        d[i][0] = (word1[i] == word2[0] && d[i-1][0] == i) ? d[i-1][0] : d[i-1][0]+1;
    for (var j = 1; j < l2; j++)
        d[0][j] = (word2[j] == word1[0] && d[0][j-1] == j) ? d[0][j-1] : d[0][j-1]+1;
    for (i = 1; i < l1; i++) {
        for (j = 1; j < l2; j++) {
            d[i][j] = Math.min(d[i-1][j], d[i][j-1]);
            if (d[i-1][j-1] <= d[i][j]) {
                d[i][j] = d[i-1][j-1];
                if (word1[i] != word2[j])
                    d[i][j]++;
            } else
                d[i][j]++;
        }
    }
    for (i = 0; i < l1; i++) {
        var s = "";
        for (j = 0; j < l2; j++)
            s += d[i][j] + ' ';
        console.log(s);
    }
    return d[l1-1][l2-1];
};

/////////////////////////////////////////////////////

var word1 = "XMJYAUZ";  //6
var word2 = "MZJAWXU";
var r = minDistance(word1, word2);
console.log(r);

