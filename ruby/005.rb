# 005
# Longest Palindromic Substring
#####################################################
# @param {String} s
# @returns {String}
def longest_palindrome(s)
# central expansion
  slen = s.size
  return s if slen <= 1

  longest_start = 0
  longest_len = 1

  (1...slen).each do |i|
    # palindrome even length
    p = i
    q = p - 1
    while q >= 0 && p < slen && s[q] == s[p]
      p += 1
      q -= 1
    end
    tlen = p - q - 1;
    if tlen > longest_len
      longest_start = q + 1
      longest_len = tlen
    end

    # palindrome odd length
    p = i
    q = p - 2
    while q >= 0 && p < slen && s[q] == s[p]
      p += 1
      q -= 1
    end
    tlen = p - q - 1
    if tlen > longest_len
      longest_start = q + 1
      longest_len = tlen
    end
  end
  s[longest_start, longest_len]
end

#####################################################
# @param {String} s
# @return {String}
def longest_palindrome2(s)
# Manacher's algorithm
  slen = s.size
  return s if slen <= 1

  t = "^#"
  s.each_char do |cc|
    t += cc + '#'
  end
  t += '$'

  tlen = t.size
  p = Array.new(tlen, 0)
  r = 0
  c = 0
  maxC = 0
  (1...tlen-1).each do |i|
    p[i] = i >= r ? 0 : [r-i, p[2*c-i]].min
    while t[i+p[i]+1] == t[i-p[i]-1]
      p[i] += 1
    end
    if i + p[i] > r
      c = i
      r = i + p[i]
      maxC = i if p[i] > p[maxC]
    end
  end
  s[(maxC-p[maxC]-1)/2, p[maxC]]
end

#####################################################

s = "abc"
#s = "forgeeksskeegfor"
#s = "cabcbabcbabcba"
#s = "habacdedcabag"
#s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD"

puts s

puts longest_palindrome2(s)

