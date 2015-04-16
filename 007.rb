# 007
# Reverse Integer
# 2015-04-12
#####################################################
# @param {Integer} x
# @returns {Integer}
def reverse(x)
  return -reverse(-x) if x < 0
  z = 0
  while x != 0
    z = z * 10 + x % 10
    x /= 10
  end

  return 0 if z > 2147483647 or z < -2147483648
  z
end

#####################################################

x = 1534236469
puts x
puts reverse(x)

