//  071
//  Simplify Path
//  2015-12-23
/////////////////////////////////////////////////////
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var v = [];
    var dirs = path.split('/');
    for (var i = 0; i < dirs.length; i++) {
        if (dirs[i] == '..')
            v.pop();
        else if (dirs[i] != '.' && dirs[i] != '')
            v.push(dirs[i]);
    }
    if (v.length == 0)
        return '/';
    return '/'+v.join('/');
};

/////////////////////////////////////////////////////
var path = "/.../";
var r = simplifyPath(path);
console.log(r);

