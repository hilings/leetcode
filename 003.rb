# 003
# Longest Substring Without Repeating Characters
#####################################################
# @param {string} s
# @return {Integer}
def length_of_longest_substring(s)
  longest = 0
  tmp = 0
  head = 0
  tail = 0

  while tail < s.length
    c = s[tail]
    if not s[head...tail].include? c
      tmp += 1
    elsif c == s[head]
      head += 1
    else
      longest = tmp if tmp > longest
      head += s[head...tail].index(c) + 1
      tmp = tail - head + 1
    end
    puts "#{head} #{tail} #{tmp}"
    tail += 1
  end
  longest = tmp if tmp > longest
  longest
end

#####################################################

s = "epqcrkeyjzbkvkrganbg"
puts s
puts length_of_longest_substring(s)

