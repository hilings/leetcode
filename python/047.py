#   047
#   Permutations II
#   2015-09-04
#####################################################
class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def nextPermutation(self, nums):
        n = len(nums)
        if n <= 1:
            return False
        i = n - 2
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        if i >= 0:
            b = min([a for a in nums[i+1:] if a > nums[i]])
            index = i+1 + nums[i+1:].index(b)
            nums[i], nums[index] = nums[index], nums[i]
        nums[i+1:] = sorted(nums[i+1:])
        return i >= 0

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        v = [nums[:]]
        while self.nextPermutation(nums):
            v.append(nums[:])
        return v
        
#####################################################

nums = [1,3,2]
sol = Solution()
z = sol.permuteUnique(nums)
print(z)

