#   026
#   Remove Duplicates from Sorted Array
#   2015-05-02
#####################################################
class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        size = len(A)
        if size == 0:
            return 0
        k = 1
        for i in range(1, size):
            if A[i] != A[i-1]:
                if k < i:
                    A[k] = A[i]
                k+=1
        print(k)
        return k
#####################################################
a = [1, 2, 3, 3]

sol = Solution()
sol.removeDuplicates(a)

