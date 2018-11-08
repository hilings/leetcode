# 010
# Regular Expression Matching
# 2015-04-18
#####################################################
# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
  l1 = s.size
  l2 = p.size

  i = 0
  j = 0
  while i <= l1 and j < l2
    if p[j+1] == '*'
      if s[i] != p[j] and p[j] != '.'
        j+=2
      elsif is_match(s[i..-1], p[j+2..-1])
        return true
      elsif s[i] == p[j] or p[j] == '.'
        i+=1
      else
        return false
      end
    elsif s[i] == p[j] or p[j] == '.'
      i+=1
      j+=1
    else
      break;
    end
  end

  i == l1 and j == l2
end

#####################################################
# @param {String} s
# @param {String} p
# @return {Boolean}

# DP
def is_match2(s, p)
  l1 = s.size
  m = Array.new(l1+1) {false}
  m[0] = true
  0.upto(p.size-1) do |j|
    if p[j+1] == '*'
      next
    elsif p[j] == '*'
      c = p[j-1]
      1.upto(l1) do |i|
        m[i] = (m[i] or (m[i-1] and (s[i-1] == c or c == '.')))
      end
    else
      c = p[j]
      l1.downto(1) do |i|
        m[i] = (m[i-1] and (s[i-1] == c or c == '.'))
      end
      m[0] = false
    end
  end
  m[l1]
end

#####################################################
s = "aaa";
p = "a*a";
#s = "ab";
#p = ".*..c*";
#s = "baccbbcbcacacbbc";
#p = "c*.*b*c*ba*b*b*.a*";

puts s
puts p
puts is_match(s, p)

