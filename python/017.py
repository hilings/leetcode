#   017
#   Letter Combinations of a Phone Number
#   2015-04-23
#####################################################
class Solution:
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        v = []
        for i in range(0, len(digits)):
            d = ord(digits[i]) - ord('0')
            letters = map[d]
            num = len(v)
            if num == 0:
                for c in letters:
                    v.append(c)
            else:
                for j in range(0, len(letters)-1):
                    for k in range(0, num):
                        v.append(v[k])
                for j in range(0, len(letters)):
                    for k in range(0, num):
                        v[num*j+k] += letters[j]
        return v
#####################################################

digits = "23"
print(digits)

sol = Solution()
z = sol.letterCombinations(digits)
print(z)

