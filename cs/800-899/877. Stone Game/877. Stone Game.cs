using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _877.Stone_Game
{
    public class Solution
    {
        private int[,] memo;

        public bool StoneGame(int[] piles)
        {
            int n = piles.Length;
            memo = new int[n, n];   // mem for calculated results
            return dp(piles, 0, n - 1) > 0;
        }

        private int dp(int[] piles, int i, int j)   // score difference
        {
            if (i >= j)
            {
                return 0;
            }
            if (memo[i, j] != 0)
            {
                return memo[i, j];
            }
            memo[i, j] = Math.Max(
                Math.Abs(piles[i] - piles[j]) + dp(piles, i + 1, j - 1),
                Math.Max(
                    piles[i] - piles[i+1] + dp(piles, i + 2, j),
                    piles[j] - piles[j-1] + dp(piles, i, j - 2)
                )
            );
            //Console.WriteLine("memo[{0}, {1}] = {2}", i, j, memo[i,j]);
            return memo[i, j];
        }

        public bool StoneGame2(int[] piles)
        {
            return true;    // Alice always wins
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int[] piles = new int[] {5, 3, 4, 5};   // true
            Console.WriteLine(sol.StoneGame(piles));
            Console.WriteLine();
            Console.WriteLine(sol.StoneGame2(piles));
            Console.WriteLine();

            piles = new int[] {3, 7, 2, 3};   // true
            Console.WriteLine(sol.StoneGame(piles));
            Console.WriteLine();
            Console.WriteLine(sol.StoneGame2(piles));
            Console.WriteLine();
        }
    }
}
