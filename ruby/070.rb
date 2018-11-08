# 070
# Climbing Stairs
# 2015-12-23
#####################################################
# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  return 0 if n == 0
  last2, last1 = 1, 1
  2.upto(n) do
    last2, last1 = last1, last1+last2
  end
  last1
end

#####################################################
n = 4
r = climb_stairs(n)
puts r

