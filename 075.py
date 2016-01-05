#   075
#   Sort Colors
#   2016-01-04
#####################################################
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l, i, j = len(nums), 0, len(nums)-1
        while i < j:
            while i < l and nums[i] == 0:
                i+=1
            while j >= 0 and nums[j] >= 1:
                j-=1
            if i < j:
                nums[i], nums[j] = nums[j], nums[i]
        j = l-1
        while i < j:
            while i < l and nums[i] == 1:
                i+=1
            while j >= 0 and nums[j] == 2:
                j-=1
            if i < j:
                nums[i], nums[j] = nums[j], nums[i]
            
#####################################################
sol = Solution()
nums = [2,1,0,2,0,2,1,0,2]
sol.sortColors(nums)
print nums

