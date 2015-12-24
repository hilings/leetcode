# 066
# Plus One
# 2015-12-21
#####################################################
# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
  c = 1
  (digits.size-1).downto(0) do |i|
    break if c == 0
    digits[i] += 1
    c = digits[i] / 10
    digits[i] %= 10
  end
  digits.unshift(1) if c == 1
  digits
end

#####################################################
digits = [9,9,9]
r = plus_one(digits)
print r

