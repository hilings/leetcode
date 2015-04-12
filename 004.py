#   004
#   Median of Two Sorted Arrays
#####################################################
class Solution:
    def median(self, a):
        b = sorted(a)
        l = len(b)
        c = l / 2
        if l % 2 == 1:
            return b[c]
        else:
            return (b[c-1] + b[c]) / 2.0

    # @return a float
    def findMedianSortedArrays(self, A, B):
        print(A)
        print(B)
        l1 = len(A)
        l2 = len(B)
        if l1 > l2:
            return self.findMedianSortedArrays(B, A)

        c = l2 / 2
        if l1 == 0:
            if l2 % 2 == 1:
                return B[c]
            else:
                return self.median([B[c-1], B[c]])
        elif l1 == 1:
            if l2 == 1:
                return self.median([A[0], B[0]])
            elif l2 % 2 == 1:
                return self.median([A[0], B[c-1], B[c], B[c+1]])
            else:
                return self.median([A[0], B[c-1], B[c]])
        elif l1 == 2:
            if l2 == 2:
                return self.median([A[0], A[1], B[0], B[1]])
            elif l2 % 2 == 1:
                return self.median([max(A[0], B[c-1]), B[c], min(A[1], B[c+1])])
            else:
                return self.median([max(A[0], B[c-2]), B[c-1], B[c], min(A[1], B[c+1])])
        else:
            h = l1 / 2
            if A[h] > B[c]:
                return self.findMedianSortedArrays(A[:h+1], B[l1-h-1:])
            else:
                if l1 % 2 == 0:
                    h -= 1
                return self.findMedianSortedArrays(A[h:], B[:-h])

#####################################################

A = [];
B = [2];
A = [2, 2, 2, 2];
B = [2, 2, 2];
A = [1, 2, 4, 8, 9, 10];
B = [3, 5, 6, 7 ];

print A
print B

sol = Solution()
print sol.findMedianSortedArrays(A, B)

