#   067
#   Add Binary
#   2015-12-21
#####################################################
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) < len(b):
            return self.addBinary(b, a)
        aa, i, j, c = list(a), len(a)-1, len(b)-1, 0
        while j >= 0:
            t = int(a[i]) + int(b[j]) + c
            aa[i], c, i, j = str(t%2), t/2, i-1, j-1
        while i >= 0:
            t = int(a[i]) + c
            aa[i], c, i = str(t%2), t/2, i-1
        if c == 1:
            aa.insert(0, '1')
        return "".join(aa)

#####################################################
sol = Solution()

a = "111"
b = "110"
r = sol.addBinary(a, b)
print r

