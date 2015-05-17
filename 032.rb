# 032
# Longest Valid ParenthesesXXX
# 2015-05-10
#####################################################
# @param {String} s
# @return {Integer}
def longest_valid_parentheses(s)
  stack = [-1]
  count = 0
  for i in (0...s.size)
    if s[i] == '('
      stack.push(i)
    elsif stack.last != -1 and s[stack.last] == '('
      stack.pop
      count = [count, i - stack.last].max
    else
      stack.push(i)
    end
  end
  count
end

#####################################################

s = "()()"
puts longest_valid_parentheses(s)

