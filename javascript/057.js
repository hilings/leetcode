//  057
//  Insert Interval
//  2015-12-15
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
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(intervals, newInterval) {
    var index_start = intervals.length;
    var index_end = intervals.length-1;
    for (var i in intervals) {
        if (newInterval.start <= intervals[i].end) {
            index_start = i;
            if (intervals[i].start < newInterval.start)
                newInterval.start = intervals[i].start;
            break;
        }
    }
    for (i = index_start; i < intervals.length; i++) {
        if (newInterval.end < intervals[i].start) {
            index_end = i-1;
            break;
        } else if (newInterval.end <= intervals[i].end) {
            index_end = i;
            newInterval.end = intervals[i].end;
            break;
        }
    }
    return intervals.slice(0, index_start).concat([newInterval], intervals.slice(+index_end+1));
};

/////////////////////////////////////////////////////
var intervals = [
    new Interval(1,3),
    new Interval(6,9)
];
var newInterval = new Interval(2,4);

var r = insert(intervals, newInterval);
console.log(r);

