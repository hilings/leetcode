#   032
#   Longest Valid ParenthesesXXX
#   2015-05-10
#####################################################
class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        count = 0
        stack = [-1]
        for i in range(0, len(s)):
            if s[i] == '(':
                stack.append(i)
            elif stack[-1] != -1 and s[stack[-1]] == '(':
                stack.pop()
                count = max(count, i-stack[-1])
            else:
                stack.append(i)
        return count

#####################################################

s = "()()"
print s

sol = Solution()
print sol.longestValidParentheses(s)

