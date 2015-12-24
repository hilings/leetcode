# 069
# Sqrt(x)
# 2015-12-22
#####################################################
# @param {Integer} x
# @return {Integer}
def my_sqrt(x)
  r = 1
  r = r << 1 while r*r <= x
  step = r >> 1
  while step > 0
    r -= step if (r-step)*(r-step) > x
    step = step >> 1
  end
  r-1
end

#####################################################

x = 2147483647
r = my_sqrt(x)
puts r

puts Math.sqrt(x).to_i

