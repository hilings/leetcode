#   011
#   Container With Most Water
#   2014-04-19
#####################################################
class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        i = 0
        j = len(height) - 1
        maxA = 0
        while i < j:
            maxA = max(maxA, (j-i) * min(height[i], height[j]))
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
        return maxA

#####################################################

height = [1, 2, 4]
print(height)
sol = Solution()
z = sol.maxArea(height)
print(z)

