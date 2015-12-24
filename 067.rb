# 067
# Add Binary
# 2015-12-21
#####################################################
# @param {String} a
# @param {String} b
# @return {String}
def add_binary(a, b)
  return add_binary(b, a) if a.size < b.size
  i, j, c = a.size-1, b.size-1, 0
  while j >= 0  
    t = a[i].to_i + b[j].to_i + c
    a[i], c, i, j = (t%2).to_s, t/2, i-1, j-1
  end
  while i >= 0
    t = a[i].to_i + c
    a[i], c, i = (t%2).to_s, t/2, i-1
  end
  return "1"+a if c == 1
  a
end

#####################################################
a = "111"
b = "111"
r = add_binary(a, b)
puts r

