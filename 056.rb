# 056
# Merge Intervals
# 2015-12-11
#####################################################
# Definition for an interval.
class Interval
  attr_accessor :start, :end
  def initialize(s=0, e=0)
    @start = s
    @end = e
  end
  def to_s
    "[#{@start}, #{@end}]"
  end
end

# @param {Interval[]} intervals
# @return {Interval[]}
def merge(intervals)
  v = []
  return v if intervals.empty?
  intervals.sort!{|x,y| x.start <=> y.start}

  while intervals.size >= 2
    last = intervals.pop
    index = intervals.rindex{|x| last.start <= x.end}
    if index.nil?
      v.push(last)
    else
      lower = intervals[index].start
      upper = [intervals[index].end, last.end].max
      intervals.pop(intervals.size-index)
      intervals.push(Interval.new(lower,upper))
    end
  end
  v.push(intervals.first)
end

#####################################################

intervals = [
=begin
  Interval.new(2,6),
  Interval.new(1,3),
  Interval.new(8,10),
  Interval.new(15,18)
=end
=begin
  Interval.new(1,4),
  Interval.new(2,3)
=end
#=begin
  Interval.new(2,3),
  Interval.new(4,5),
  Interval.new(6,7),
  Interval.new(8,9),
  Interval.new(1,10)
#=end
=begin
  Interval.new(1,4),
  Interval.new(0,2),
  Interval.new(3,5)
=end

]

puts merge(intervals)

