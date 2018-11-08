#   066
#   Plus One
#   2015-12-21
#####################################################
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        c = 1
        for i in range(len(digits)-1, -1, -1):
            if c == 0:
                break
            digits[i] += 1
            c = digits[i] // 10
            digits[i] %= 10
        if c == 1:
            digits = [1] + digits
        return digits

#####################################################
sol = Solution()

digits = [9,9,9]
z = sol.plusOne(digits)
print(z)

