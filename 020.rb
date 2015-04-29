# 020
# Valid Parentheses
# 2015-04-28
#####################################################
# @param {String} s
# @return {Boolean}
def is_valid(s)
  stack = []
  s.each_char do |c|
    if (c == ')' and stack.last == '(') or (c == ']' and stack.last == '[') or (c == '}' and stack.last == '{')
      stack.pop
    else
      stack.push(c)
    end
  end
  stack.empty?
end

#####################################################
s = "]"
puts s
puts is_valid(s) ? "True" : "False"

