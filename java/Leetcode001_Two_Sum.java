import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> um = new HashMap<Integer,Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (um.containsKey(target-nums[i])) {
                return new int[] {um.get(target-nums[i]), i};
            }
            um.put(nums[i], i);
        }
        return new int[] {};
    }
}

public class Leetcode001_Two_Sum {
    public static void main(String[] args) {
        System.out.println("1. Two Sum");
        System.out.println("2018-11-09\n");

        Solution sol = new Solution();

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] z = sol.twoSum(nums, target);

        System.out.println(Arrays.toString(z));
    }
}
