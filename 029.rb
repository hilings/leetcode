# 029
# Divide Two Integers
# 2015-05-04
#####################################################
# @param {Integer} dividend
# @param {Integer} divisor
# @return {Integer}
def divide(dividend, divisor)
  return 0 if divisor == 0
  sign = ((dividend > 0) ^ (divisor > 0))
  dividend = -dividend if dividend < 0
  divisor = -divisor if divisor < 0

  int_max = 2147483647
  d = [divisor]
  i = 1
  while d[i-1] < dividend and d[i-1] < int_max
    d[i] = d[i-1] + d[i-1]
    i+=1
  end
  i-=1
  res = 0
  while dividend >= divisor
    while d[i] > dividend and i > 0
      i -= 1
    end
    r = 1
    for j in (0...i)
      r += r
    end
    res += r
    dividend -= d[i]
  end
  if sign
    res = -res
  end
  [res, int_max].min
end

#####################################################

INT_MAX = 2**31-1
INT_MIN = -2**31

dividend = INT_MIN
divisor = -1

puts "#{dividend} / #{divisor} = #{divide(dividend, divisor)}"

