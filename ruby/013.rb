# 013
# Roman to Integer
# 2015-04-20
#####################################################
# @param {String} s
# @return {Integer}
def roman_to_int(s)
  n = [  1,   5,  10,  50, 100, 500, 1000]
  c = ['I', 'V', 'X', 'L', 'C', 'D', 'M' ]

  num = 0
  i = n.size - 1
  len = s.size
  p = 0
  while p < len
    if s[p] == c[i+2]
      num = num - n[i]*2 + n[i+2]
      i-=1
      p+=1
    elsif s[p] == c[i+1]
      num = num - n[i]*2 + n[i+1]
      i-=1
      p+=1
    elsif s[p] == c[i]
      num += n[i]
      p+=1
    else
      i-=1
    end
  end
  num
end

#####################################################

s = "IX"
puts s
puts roman_to_int(s)

