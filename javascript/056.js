//  056
//  Merge Intervals
//  2015-12-13
/////////////////////////////////////////////////////
/**
 * Definition for an interval.
 */
function Interval(start, end) {
    this.start = start;
    this.end = end;
}
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
    intervals.sort(function(a,b) {return a.start-b.start;});
    if (intervals.length == 0)
        return [];
    var r = [intervals[0]];
    for (var i = 1; i < intervals.length; i++)
        if (intervals[i].start <= r[r.length-1].end)
            r[r.length-1].end = Math.max(intervals[i].end, r[r.length-1].end);
        else
            r.push(intervals[i]);
    return r;
};

/////////////////////////////////////////////////////
var intervals = [
    new Interval(2,6),
    new Interval(1,3),
    new Interval(8,10),
    new Interval(15,18)
/*
    new Interval(1,4),
    new Interval(2,3)

    new Interval(2,3),
    new Interval(4,5),
    new Interval(6,7),
    new Interval(8,9),
    new Interval(1,10)

    new Interval(1,4),
    new Interval(0,2),
    new Interval(3,5)
*/
];

var r = merge(intervals);
console.log(r);

