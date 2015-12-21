#   065
#   Valid Number
#   2015-12-20
#####################################################
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i, l = 0, len(s)
        while i < l and s[i] == ' ':
            i+=1
        if i == l:
            return False
        if s[i] == '+' or s[i] == '-':
            i+=1
        while self.myisdigit(s, i):
            i+=1
        if i < l and s[i] == '.':
            if not self.myisdigit(s, i-1) and not self.myisdigit(s, i+1):
                return False 
            i+=1
        while self.myisdigit(s, i):
            i+=1
        if i < l and s[i] == 'e':
            if not self.myisdigit(s, i-1) and not self.myisdigit(s, i-2):
                return False
            if not self.myisdigit(s, i+1) and not self.myisdigit(s, i+2):
                return False
            i+=1
            if (s[i] == '+' or s[i] == '-') and self.myisdigit(s, i+1):
                i+=1
        while self.myisdigit(s, i):
            i+=1
        while i < len(s) and s[i] == ' ':
            i+=1
        return i == len(s)

    def myisdigit(self, s, i):
        if i < 0 or i >= len(s):
            return False
        return s[i].isdigit()

#####################################################
sol = Solution()

s = "+1"
r = sol.isNumber(s)
print r

