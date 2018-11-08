# 012
# Integer to Roman
# 2015-04-20
#####################################################
# @param {Integer} num
# @return {String}
def int_to_roman(num)
  n = [  1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000]
  c = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" ]
  str = "";
  i = n.size - 1
  while num > 0
    if num < n[i]
      i-=1
      next
    end
    str += c[i]
    num -= n[i]
  end
  str
end

#####################################################

(0..15).each do |i|
  puts "#{i}    #{int_to_roman(i)}"
end

