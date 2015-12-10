#   053
#   Maximum Subarray
#   2015-12-08
#####################################################
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum = tmp = nums[0]
        for a in nums[1:]:
            tmp = max(tmp+a, a)
            sum = max(sum, tmp)
        return sum
        

#####################################################

nums = [-2,1,-3,4,-1,2,1,-5,4]

sol = Solution()

print sol.maxSubArray(nums)

