#   027
#   Remove Element
#   2015-05-03
#####################################################
class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        printFirstN(A, len(A))
        n = len(A)
        k = n - 1
        i = 0
        while i <= k:
            if A[i] == elem:
                while k > i and A[k] == elem:
                    k-=1
                if i < k:
                    A[i] = A[k]
                k-=1
            i+=1
        printFirstN(A, k+1)
        return k+1

def printFirstN(A, n):
    for i in range(0, n):
        print A[i],
    print

#####################################################
a = [1, 2, 2]
elem = 2

sol = Solution()
sol.removeElement(a, elem)

