#   014
#   Longest Common Prefix
#   2014-04-20
#####################################################
class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ""
        prefix = ""
        for i in range(0, len(strs[0])):
            c = strs[0][i]
            for j in range(0, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != c:
                    return prefix
            prefix += c
        return prefix

#####################################################

strs = ["abc", "abd", "abe"]
print strs
sol = Solution()
print sol.longestCommonPrefix(strs)

