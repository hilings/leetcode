# 006
# ZigZag Conversion
# 2015-04-12
#####################################################
# @param {String} s
# @param {Integer} nrows
# @returns {String}
def convert(s, nrows)
  return s if nrows == 1
  len = s.size
  str = "";
  for r in (0...nrows)
    for i in (r...len).step(2*nrows-2)
      str += s[i]
      if r != 0 and r != nrows-1
        t = i + 2*nrows - 2 - 2*r
        str += s[t] if t < len
      end
    end
  end
  str
end

#####################################################

s = "0123456789"
nrows = 4

puts s
puts convert(s, nrows)

