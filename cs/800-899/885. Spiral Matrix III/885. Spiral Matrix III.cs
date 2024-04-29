using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _885.Spiral_Matrix_III
{
    public class Solution
    {
        public int[][] SpiralMatrixIII(int rows, int cols, int rStart, int cStart)
        {
            int[][] directions = new int[][]
            {
                new int[] { 0, 1 },  // right
                new int[] { 1, 0 },  // down
                new int[] { 0, -1 }, // left
                new int[] { -1, 0 }  // up
            };
            int currentDirection = 0;
            int steps = 1;  // steps to walk in the current direction
            int moves = 0;  // moves walked in the current direction

            List<int[]> cells = new List<int[]> { new int[] {rStart, cStart} };
            for (int i = rStart, j = cStart; cells.Count < rows * cols; )
            {
                int[] next = new int[] { i + directions[currentDirection][0], j + directions[currentDirection][1] };
                if (next[0] >= 0 && next[0] < rows && next[1] >= 0 && next[1] < cols)
                {
                    cells.Add(next);
                }
                i = next[0];
                j = next[1];
                moves++;
                if (moves == steps)
                {
                    moves = 0;
                    currentDirection = (currentDirection + 1) % 4;
                    if (currentDirection % 2 == 0)
                    {
                        steps++;
                    }
                }
            }
            return cells.ToArray();
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int rows = 1, cols = 4, rStart = 0, cStart = 0;
            int[][] cells = sol.SpiralMatrixIII(rows, cols, rStart, cStart);
            Console.WriteLine(string.Join(",", cells.Select(cell => string.Format("[{0},{1}]", cell[0], cell[1]))));
            Console.WriteLine();

            rows = 5;
            cols = 6;
            rStart = 1;
            cStart = 4;
            cells = sol.SpiralMatrixIII(rows, cols, rStart, cStart);
            Console.WriteLine(string.Join(",", cells.Select(cell => string.Format("[{0},{1}]", cell[0], cell[1]))));
            Console.WriteLine();
        }
    }
}
