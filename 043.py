#   043
#   Multiply Strings
#   2015-05-19
#####################################################
class Solution:
    # @param {string} num1
    # @param {string} num2
    # @return {string}
    def multiply(self, num1, num2):
        l1 = len(num1)
        l2 = len(num2)
        s = [0]*(l1+l2)
        for i in reversed(range(l1)):
            carry = 0
            for j in reversed(range(l2)):
                tmp = s[i+j+1] + int(num1[i])*int(num2[j]) + carry
                s[i+j+1] = tmp % 10
                carry = tmp / 10
            s[i] += carry
        for i in range(l1+l2):
            if s[i] != 0:
                return ''.join(map(str, s[i:]))
        return "0"

#####################################################

num1 = "9"
num2 = "9"

sol = Solution()
print sol.multiply(num1, num2)

