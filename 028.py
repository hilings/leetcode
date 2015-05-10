#   028
#   Implement strStr()
#   2015-05-03
#####################################################
class Solution:
    # @param {string} haystack
    # @param {string} needle
    # @return {integer}
    def strStr(self, haystack, needle):
        if len(needle) == 0:
            return 0
        for i in range(0, len(haystack)):
            if haystack[i] != needle[0]:
                continue
            k = i
            j = 0
            while j < len(needle):
                if k == len(haystack):
                    return -1
                if haystack[k] == needle[j]:
                    k+=1
                    j+=1
                else:
                    break
            if j == len(needle):
                return i
        return -1

    def strStr0(self, haystack, needle):
        return haystack.find(needle)

    def strStr2(self, haystack, needle):    # KMP
        l2 = len(needle)
        if l2 == 0:
            return 0
        T = [-1]
        for j in range(1, l2):
            if T[j-1] > -1 and needle[j-1] == needle[T[j-1]]:
                T.append(T[j-1] + 1)
            else:
                T.append(0)
        l1 = len(haystack)
        i = 0
        j = 0
        while i + j < l1:
            if haystack[i+j] == needle[j]:
                if j == l2 - 1:
                    return i
                else:
                    j+=1
            else:
                if T[j] > -1:
                    i = i + j - T[j]
                    j = T[j]
                else:
                    i += 1
                    j = 0
        return -1

#####################################################
haystack = "ABC ABCDAB ABCDABCDABDE"
needle = "ABCDABD"

sol = Solution()
print sol.strStr2(haystack, needle)

