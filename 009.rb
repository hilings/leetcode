# 009
# Palindrome Number
# 2014-04-14
#####################################################
# @param {Integer} x
# @return {Boolean}
def is_palindrome(x)
  return false if x < 0
  shade = 1
  while x >= shade * 10
    shade *= 10
  end
  while shade >= 10 and x / shade == x % 10
    x %= shade
    x /= 10
    shade /= 100
  end
  shade < 10
end

#####################################################
# @param {Integer} x
# @return {Boolean}
def is_palindrome2(x)
  x.to_s.reverse.to_i == x
end

#####################################################

x = 1874994781
puts is_palindrome2(x) ? 'true' : 'false'

