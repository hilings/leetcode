# 042
# Trapping Rain Water
# 2015-05-18
#####################################################
# @param {Integer[]} height
# @return {Integer}
def trap(height)
  n = height.size
  return 0 if n == 0
  l = []
  r = []
  l[0] = height[0]
  r[n-1] = height[n-1]
  for i in (1..n-1)
    j = n-1-i
    l[i] = [height[i], l[i-1]].max
    r[j] = [height[j], r[j+1]].max
  end
  sum = 0
  for i in (1...n-1)
    roof = [l[i], r[i]].min
    sum += roof - height[i] if height[i] < roof
  end
  sum
end

#####################################################

height = [0,1,0,2,1,0,1,3,2,1,2,1]
puts trap(height)

