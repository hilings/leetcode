# 005
# Longest Palindromic Substring
#####################################################
# @param {String} s
# @returns {String}
def longest_palindrome(s)
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

s = "";
s = "a";
s = "aa";
s = "ab";
s = "abc";
s = "abb";
s = "aba";
s = "aaa";
s = "forgeeksskeegfor";
s = "cabcbabcbabcba";
s = "habacdedcabag";
s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD";

puts s

puts longest_palindrome(s)



