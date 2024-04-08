using System;
using System.Collections.Generic;

namespace _873.Length_of_Longest_Fibonacci_Subsequence
{
    public class Solution
    {
        public int LenLongestFibSubseq(int[] arr)
        {
            HashSet<int> hs = new HashSet<int>(arr);
            int r = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    int a = arr[i], b = arr[j], l = 2;
                    while (hs.Contains(a + b))
                    {
                        b = a + b;
                        a = b - a;
                        l++;
                    }
                    if (l > 2)
                    {
                        r = Math.Max(r, l);
                    }
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
            int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
            Solution sol = new Solution();
            int r = sol.LenLongestFibSubseq(arr);
            Console.WriteLine(r);

            arr = new int[] { 1, 3, 7, 11, 12, 14, 18 };
            r = sol.LenLongestFibSubseq(arr);
            Console.WriteLine(r);
        }
    }
}
