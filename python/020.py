#   020
#   Valid Parentheses
#   2015-04-28
#####################################################
class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        stack = []
        for c in s:
            if not stack:
                stack.append(c)
            elif (c == ')' and stack[-1] == '(') or (c == ']' and stack[-1] == '[') or (c == '}' and stack[-1] == '{'):
                stack.pop()
            else:
                stack.append(c)
        return not stack

#####################################################

s = "]"
print(s)
sol = Solution()
z = sol.isValid(s)
print("True" if z else "False")

