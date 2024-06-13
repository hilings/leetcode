using System;

namespace _892.Surface_Area_of_3D_Shapes
{
    public class Solution
    {
        public int SurfaceArea(int[][] grid)
        {
            int r = 0;
            for (int i = 0; i < grid.Length; i++)
            {
                for (int j = 0; j < grid[i].Length; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        continue;
                    }

                    r += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                    if (i - 1 >= 0)
                    {
                        r -= Math.Min(grid[i][j], grid[i - 1][j]);
                    }
                    if (j - 1 >= 0)
                    {
                        r -= Math.Min(grid[i][j], grid[i][j - 1]);
                    }
                    if (i + 1 < grid.Length)
                    {
                        r -= Math.Min(grid[i][j], grid[i + 1][j]);
                    }
                    if (j + 1 < grid[i].Length)
                    {
                        r -= Math.Min(grid[i][j], grid[i][j + 1]);
                    }
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int[][] grid = new int[][]
            {
                new int[] { 1, 2 },
                new int[] { 3, 4 },
            };
            int r = sol.SurfaceArea(grid); // 34
            Console.WriteLine(r);

            grid = new int[][]
            {
                new int[] { 1, 1, 1 },
                new int[] { 1, 0, 1 },
                new int[] { 1, 1, 1 },
            };
            r = sol.SurfaceArea(grid); // 32
            Console.WriteLine(r);

            grid = new int[][]
            {
                new int[] { 2, 2, 2 },
                new int[] { 2, 1, 2 },
                new int[] { 2, 2, 2 },
            };
            r = sol.SurfaceArea(grid); // 46
            Console.WriteLine(r);
        }
    }
}