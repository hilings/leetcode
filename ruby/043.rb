# 043
# Multiply Strings
# 2015-05-19
#####################################################
# @param {String} num1
# @param {String} num2
# @return {String}
def multiply(num1, num2)
  l1 = num1.size
  l2 = num2.size
  s = "0"*(l1+l2)
  (l1-1).downto(0) do |i|
    carry = 0
    (l2-1).downto(0) do |j|
      tmp = s[i+j+1].to_i + num1[i].to_i * num2[j].to_i + carry
      s[i+j+1] = (tmp % 10).to_s
      carry = tmp / 10
    end
    s[i] = (s[i].to_i + carry).to_s
  end
  index = s.index(/[1-9]/)
  index ? s[index..-1]: "0";
end

#####################################################

num1 = "12"
num2 = "23"
puts multiply(num1, num2)

