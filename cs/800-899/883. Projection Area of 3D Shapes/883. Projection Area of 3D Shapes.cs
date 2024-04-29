using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _883.Projection_Area_of_3D_Shapes
{
    public class Solution
    {
        public int ProjectionArea(int[][] grid)
        {
            int n = grid.Length;
            int xy = 0, xz = 0, yz = 0;
            for (int i = 0; i < n; i++)
            {
                int maxZperX = 0, maxZperY = 0;
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] > 0)
                    {
                        xy++;
                    }
                    maxZperX = Math.Max(maxZperX, grid[i][j]);  // max z for each x
                    maxZperY = Math.Max(maxZperY, grid[j][i]);  // max z for each y
                }
                xz += maxZperX;
                yz += maxZperY;
            }
            return xy + xz + yz;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[][] grid = new int[][]
            {
                new int[] { 1, 2 },
                new int[] { 3, 4 }
            };
            Console.WriteLine(sol.ProjectionArea(grid));   // 17
            Console.WriteLine();

            grid = new int[][]
            {
                new int[] { 2 }
            };
            Console.WriteLine(sol.ProjectionArea(grid));   // 5
            Console.WriteLine();

            grid = new int[][]
            {
                new int[] { 1, 0 },
                new int[] { 0, 2 }
            };
            Console.WriteLine(sol.ProjectionArea(grid));   // 8
            Console.WriteLine();
        }
    }
}
