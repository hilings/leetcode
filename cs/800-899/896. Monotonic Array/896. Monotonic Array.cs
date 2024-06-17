using System;

namespace _896.Monotonic_Array
{
    public class Solution
    {
        public bool IsMonotonic(int[] nums)
        {
            int trend = 0;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] == nums[i - 1])
                {
                    continue;
                }

                if (trend == 0)
                {
                    trend = nums[i] > nums[i - 1] ? 1 : -1;
                    continue;
                }

                if ((nums[i] > nums[i - 1] && trend == -1) || (nums[i] < nums[i - 1] && trend == 1))
                {
                    return false;
                }
            }

            return true;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] nums = { 1, 2, 2, 3 };
            bool r = sol.IsMonotonic(nums);
            Console.WriteLine(r);

            nums = new int[] { 6, 5, 4, 4 };
            r = sol.IsMonotonic(nums);
            Console.WriteLine(r);

            nums = new int[] { 1, 3, 2 };
            r = sol.IsMonotonic(nums);
            Console.WriteLine(r);
        }
    }
}
