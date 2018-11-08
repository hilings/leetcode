# 057
# Insert Interval
# 2015-12-15
#####################################################
# Definition for an interval.
class Interval
  attr_accessor :start, :end
  def initialize(s=0, e=0)
    @start = s
    @end = e
  end
  def to_s
    "[#{@start},#{@end}]"
  end
end

# @param {Interval[]} intervals
# @param {Interval} new_interval
# @return {Interval[]}
def insert(intervals, new_interval)
  index_start = intervals.size
  index_end = intervals.size-1
  intervals.each_with_index do |a, i|
    if new_interval.start <= a.end 
      new_interval.start = a.start if a.start < new_interval.start
      index_start = i
      break
    end
  end
  intervals[index_start..-1].each_with_index do |a,i|
    if new_interval.end < a.start
      index_end = index_start+i-1
      break
    elsif new_interval.end <= a.end
      new_interval.end = a.end
      index_end = index_start+i
      break
    end
  end
  intervals[0...index_start]+[new_interval]+intervals[index_end+1..-1]
end

#####################################################

intervals = [
=begin
  Interval.new(1,3),
  Interval.new(6,9)
=end
  Interval.new(1,2),
  Interval.new(3,5),
  Interval.new(6,7),
  Interval.new(8,10),
  Interval.new(12,16)
]
#new_interval = Interval.new(2,5)
new_interval = Interval.new(4,9)

r = insert(intervals, new_interval)
r.each {|a| puts a}

