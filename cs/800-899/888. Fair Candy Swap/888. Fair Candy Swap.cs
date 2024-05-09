using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _888.Fair_Candy_Swap
{
    public class Solution
    {
        public int[] FairCandySwap(int[] aliceSizes, int[] bobSizes)
        {
            int sumA = 0, sumB = 0;
            HashSet<int> setA = new HashSet<int>(), setB = new HashSet<int>();
            foreach (int a in aliceSizes)
            {
                sumA += a;
                setA.Add(a);
            }
            foreach (int b in bobSizes)
            {
                sumB += b;
                setB.Add(b);
            }
            int diff = (sumA - sumB) / 2;
            int[] r = new int[2];
            foreach (int a in setA)
            {
                if (setB.Contains(a - diff))
                {
                    r = new int[] { a, a - diff };
                    break;
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] aliceSizes = new int[] { 1, 1 };
            int[] bobSizes = new int[] { 2, 2 };
            int[] r = sol.FairCandySwap(aliceSizes, bobSizes);
            Console.WriteLine($"[{string.Join(",", r)}]"); // [1,2]
            Console.WriteLine();

            aliceSizes = new int[] { 1, 2 };
            bobSizes = new int[] { 2, 3 };
            r = sol.FairCandySwap(aliceSizes, bobSizes);  // [1,2] or [2,3]
            Console.WriteLine($"[{string.Join(",", r)}]");
            Console.WriteLine();

            aliceSizes = new int[] { 2 };
            bobSizes = new int[] { 1, 3 };
            r = sol.FairCandySwap(aliceSizes, bobSizes);  // [2,3]
            Console.WriteLine($"[{string.Join(",", r)}]");
            Console.WriteLine();
        }
    }
}
