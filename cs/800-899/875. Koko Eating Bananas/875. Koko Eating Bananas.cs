using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _875.Koko_Eating_Bananas
{
    public class Solution
    {
        public int MinEatingSpeed(int[] piles, int h)
        {
            int highest = 0;
            foreach (int pile in piles)
            {
                highest = Math.Max(highest, pile);
            }

            int left = 1, right = highest;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (requiredHours(piles, mid) <= h)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return left;
        }

        public int requiredHours(int[] piles, int k)
        {
            int h = 0;
            for (int i = 0; i < piles.Length; i++)
            {
                h += (piles[i] + k - 1) / k;
            }
            return h;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int[] piles = new int[] {3, 6, 7, 11};
            int h = 8;

            Console.WriteLine(sol.MinEatingSpeed(piles, h));
            Console.WriteLine();

            piles = new int[] {30, 11, 23, 4, 20};
            h = 5;
            Console.WriteLine(sol.MinEatingSpeed(piles, h));
            Console.WriteLine();

            piles = new int[] {30, 11, 23, 4, 20};
            h = 6;
            Console.WriteLine(sol.MinEatingSpeed(piles, h));
            Console.WriteLine();
        }
    }
}
