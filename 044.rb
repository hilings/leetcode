# 044
# Wildcard Matching
# 2015-06-23
#####################################################
# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
  l1 = s.size
  return false if l1 < p.size - p.count('*')

  m = Array.new(l1+1) {false}
  m[0] = true

  p.each_char do |c|
    if c == '*'
      1.upto(l1) do |i|
        m[i] = (m[i-1] or m[i])
      end
    else
      l1.downto(1) do |i|
        m[i] = (m[i-1] and (s[i-1] == c or c == '?'))
      end
      m[0] = false
    end
  end
  m[l1]
end

#####################################################
s = "aa"
p = "a*"

puts s
puts p
puts is_match(s, p)

