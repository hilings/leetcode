# 050
# Pow(x, n)
# 2015-09-14
#####################################################
# @param {Float} x
# @param {Integer} n
# @return {Float}
def my_pow(x, n)
  return 1 if n == 0
  if n < 0
    x = 1/x
    n = -n
  end
  result = 1
  while n > 0
    result *= n&1>0 ? x : 1
    x *= x
    n = n>>1
  end
  result
end

#####################################################

puts my_pow(3.89707, 2)

