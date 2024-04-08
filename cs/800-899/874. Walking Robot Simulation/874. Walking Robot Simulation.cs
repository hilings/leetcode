using System;
using System.Collections.Generic;
using System.Linq;

namespace _874.Walking_Robot_Simulation
{
    public class Solution
    {
        public int RobotSim(int[] commands, int[][] obstacles)
        {
            int[][] directions = new int[][] {
                new int[] {0, 1},  // North
                new int[] {1, 0},  // East
                new int[] {0, -1}, // South
                new int[] {-1, 0}  // West
            };
            HashSet<string> hsObstacles = new HashSet<string>();
            foreach (int[] obstacle in obstacles)
            {
                hsObstacles.Add(string.Join(",", obstacle));
                Console.WriteLine("obstacle: {0}", string.Join(",", obstacle));
            }
            int direction = 0;
            int[] pos = new int[] {0, 0};
            int r = 0;

            for (int i = 0; i < commands.Length; i++)
            {
                if (commands[i] == -1)
                {
                    direction = (direction + 1) % 4;
                }
                else if (commands[i] == -2)
                {
                    direction = (direction + 3) % 4;
                }
                else
                {
                    pos = endPos(pos, directions[direction], commands[i], hsObstacles);
                    r = Math.Max(r, pos[0] * pos[0] + pos[1] * pos[1]);
                }
            }

            return r;
        }

        public int[] endPos(int[] pos, int[] direction, int steps, HashSet<string> hsObstacles)
        {
            for (int i = 0; i < steps; i++)
            {
                int[] nextPos = new int[] { pos[0] + direction[0], pos[1] + direction[1] };
                Console.WriteLine("nextPos = {0}", string.Join(",", nextPos));

                if (hsObstacles.Contains(string.Join(",", nextPos)))
                {
                    Console.WriteLine($"{string.Join(",", nextPos)} is an obstable");
                    break;
                }
                pos = nextPos;
            }
            Console.WriteLine("endPos = {0}", string.Join(",", pos));
            return pos;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int[] commands = {4, -1, 3};
            int[][] obstacles = {};
            int r = sol.RobotSim(commands, obstacles);  // 25
            Console.WriteLine(r);
            Console.WriteLine();

            commands = new int[] { 4, -1, 4, -2, 4 };
            obstacles = new int[][] { new int[]{2, 4}, new int[] { 3, 5 } };
            r = sol.RobotSim(commands, obstacles);  // 65
            Console.WriteLine(r);
            Console.WriteLine();

            commands = new int[] { 6, -1, -1, 6 };
            obstacles = new int[][] {};
            r = sol.RobotSim(commands, obstacles);  // 36
            Console.WriteLine(r);
        }
    }
}
