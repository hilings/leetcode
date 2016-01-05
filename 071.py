#   071
#   Simplify Path
#   2015-12-23
#####################################################
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        v = []
        for a in path.split('/'):
            if a != '.' and a != '' and a != '..':
                v.append(a)
            if a == '..' and v:
                v.pop()
        if not v:
            return '/'
        return '/'+'/'.join(v)

#####################################################
sol = Solution()
path = "/.../"
r = sol.simplifyPath(path)
print '^'+r+'$'

