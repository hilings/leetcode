# 008
# String to Integer (atoi)
# 2015-04-14
#####################################################

# @param {String} str
# @return {Integer}
def my_atoi(str)
  s = str.strip
  len = s.size
  i = 0
  sign = 1
  if i < len and (s[i] == '+' or s[i] == '-')
    sign = (s[i] == '+') ? 1 : -1
    i += 1
  end
  
  z = 0
  while i < len and s[i] >= '0' and s[i] <= '9' and z < 2147483647
    z = z * 10 + s[i].to_i
    i += 1
  end
  if z > 2147483647
    return (sign == 1) ? 2147483647 : -2147483648
  end
  sign * z
end

#####################################################

# @param {String} str
# @return {Integer}
def my_atoi(str)
  z = str.to_i
  if z > 2147483647
    2147483647
  elsif z < -2147483648
    -2147483648
  else
    z
  end
end

#####################################################

puts my_atoi(" \r-2147483649.11\n")

