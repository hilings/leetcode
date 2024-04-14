using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _801.Minimum_Swaps_To_Make_Sequences_Increasing
{
    public class Solution
    {
        public int MinSwap(int[] nums1, int[] nums2)
        {
            int swap = 1, notSwap = 0, min = Math.Min(swap, notSwap);
            for (int i = 1; i < nums1.Length; i++)
            {
                if (nums1[i] <= nums1[i - 1] || nums2[i] <= nums2[i - 1]) // must swap
                {   // opposite of the previous swap
                    int tmp = swap;
                    swap = notSwap + 1;
                    notSwap = tmp;
                }
                else if (nums1[i] <= nums2[i - 1] || nums2[i] <= nums1[i - 1]) // must not swap
                {   // same as the previous swap
                    swap = swap + 1;
                    //notSwap = notSwap;
                }
                else // OK to swap or not swap
                {
                    swap = min + 1;
                    notSwap = min;
                }
                min = Math.Min(swap, notSwap);
            }
            return min;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int[] nums1 = new int[] {1, 3, 5, 4};
            int[] nums2 = new int[] {1, 2, 3, 7};
            int r = sol.MinSwap(nums1, nums2);  // 1
            Console.WriteLine(r);
            Console.WriteLine();

            /*
            nums1 = new int[] {0, 3, 5, 8, 9};
            nums2 = new int[] {2, 1, 4, 6, 9};
            r = sol.MinSwap(nums1, nums2);  // 1
            Console.WriteLine(r);
            Console.WriteLine();

            nums1 = new int[] {4, 2, 3};
            nums2 = new int[] {1, 5, 6};
            r = sol.MinSwap(nums1, nums2);  // 1
            Console.WriteLine(r);
            Console.WriteLine();

            nums1 = new int[] {4, 2, 3, 7, 8, 6};
            nums2 = new int[] {1, 5, 6, 4, 5, 9};
            r = sol.MinSwap(nums1, nums2);  // 3
            Console.WriteLine(r);
            Console.WriteLine();

            nums1 = new int[] {0, 4, 4, 5, 9};
            nums2 = new int[] {0, 1, 6, 8, 10};
            r = sol.MinSwap(nums1, nums2);  // 1
            Console.WriteLine(r);
            Console.WriteLine();
             */

            nums1 = new int[] { 0, 7, 8, 10, 10, 11, 12, 13, 19, 18 };
            nums2 = new int[] { 4, 4, 5, 7, 11, 14, 15, 16, 17, 20 };
            r = sol.MinSwap(nums1, nums2);  // 4
            Console.WriteLine(r);
            Console.WriteLine();
        }
    }
}
