#   055
#   Jump Game
#   2015-12-09
#####################################################
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        til = nums[0]
        i = 0
        while i <= til:
            if i+nums[i] > til:
                til = i+nums[i]
            if til >= len(nums)-1:
                return True
            i += 1
        return False

#####################################################

nums = [2,3,1,1,4]
nums = [3,2,1,0,4]

sol = Solution()
z = sol.canJump(nums)
print(z)

