//  068
//  Text Justification
//  2015-12-22
/////////////////////////////////////////////////////
/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    var v = [];
    var line = [];
    for (var i = 0; i < words.length; i++) {
        if (line.concat(words[i]).join(' ').length > maxWidth) {
            v.push(joinLine(line, maxWidth));
            line = [];
        }
        line.push(words[i]);
    }
    v.push(joinLine(line, maxWidth, true));
    return v
};

function joinLine(line, maxWidth, last) {
    if (line.length == 1 || last == true)
        return line.join(' ') + Array(maxWidth - line.join(' ').length + 1).join(' ');
    maxWidth -= line.join('').length;
    var space = Math.floor(maxWidth / (line.length-1));
    var extra = maxWidth % (line.length-1);
    return line.slice(0, extra+1).join(Array(space+2).join(' ')) + Array(space+1).join(' ') + line.slice(extra+1).join(Array(space+1).join(' '));
}

/////////////////////////////////////////////////////
var words = ["This", "is", "an", "example", "of", "text", "justification."];
var maxWidth = 16;
var r = fullJustify(words, maxWidth);
for (var i = 0; i < r.length; i++) {
    console.log('"' + r[i] + '"');
}

