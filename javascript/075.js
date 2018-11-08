//  075
//  Sort Colors
//  2016-01-04
/////////////////////////////////////////////////////
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var i = 0, j = nums.length-1;
    while (i < j) {
        while (i < nums.length && nums[i] == 0)
            i++;
        while (j >= 0 && nums[j] >= 1)
            j--;
        if (i < j) {
            var tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    j = nums.length-1;
    while (i < j) {
        while (i < nums.length && nums[i] == 1)
            i++;
        while (j >= 0 && nums[j] == 2)
            j--;
        if (i < j) {
            var tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};

/////////////////////////////////////////////////////
var nums = [2,1,0,2,0,2,1,0,2];
sortColors(nums);
console.log(nums);

