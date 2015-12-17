#   058
#   Length of Last Word
#   2015-12-15
#####################################################
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s2 = s.rstrip()
        return len(s2)-1-s2.rfind(' ')

#####################################################
s = " asdfs asdf"
sol = Solution()
print sol.lengthOfLastWord(s)

