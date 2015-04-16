#   009
#   Palindrome Number
#   2015-04-15
#####################################################
class Solution:
    # @param x, an integer
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return True
        shade = 1
        while x >= shade * 10:
            shade *= 10
        while shade >= 10 and x / shade == x % 10:
            x %= shade
            x /= 10
            shade /= 100
        return shade < 10

####

    def isPalindrome2(self, x):
        return str(x)[::-1] == str(x)

#####################################################

x = 121
sol = Solution()

print x
print sol.isPalindrome2(x)

