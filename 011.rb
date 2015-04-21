# 011
# Container With Most Water
# 2014-04-19
#####################################################
# @param {Integer[]} height
# @return {Integer}
def max_area(height)
  i = 0
  j = height.size - 1
  maxA = 0
  while i < j
    maxA = [maxA, (j-i) * [height[i], height[j]].min].max
    height[i] < height[j] ? i+=1 : j-=1
  end
  maxA
end

#####################################################

height = [1, 2, 4]
puts max_area(height)

