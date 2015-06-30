#   042
#   Trapping Rain Water
#   2015-05-18
#####################################################
class Solution:
    # @param {integer[]} height
    # @return {integer}
    def trap(self, height):
        n = len(height)
        if n == 0:
            return 0
        l = []
        r = []
        l.append(height[0])
        r.append(height[n-1])
        for i in range(1,n):
            j = n-1-i
            l.append(max(height[i], l[i-1]))
            r.insert(0, max(height[j], r[0]))
        sum = 0
        for i in range(1,n-1):
            roof = min(l[i], r[i])
            if height[i] < roof:
                sum += roof - height[i]
        return sum
        
#####################################################

sol = Solution()

height = [0,1,0,2,1,0,1,3,2,1,2,1]
print sol.trap(height)

