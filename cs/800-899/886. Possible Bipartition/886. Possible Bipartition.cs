using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _886.Possible_Bipartition
{
    public class Solution
    {
        public bool PossibleBipartition(int n, int[][] dislikes)
        {
            HashSet<int>[] bipartitions = new HashSet<int>[2] { new HashSet<int>(), new HashSet<int>() };
            Dictionary<int, List<int>> dislikesPerPerspon = new Dictionary<int, List<int>>();
            foreach (int[] dislike in dislikes)
            {
                if (!dislikesPerPerspon.ContainsKey(dislike[0]))
                {
                    dislikesPerPerspon.Add(dislike[0], new List<int>());
                }
                dislikesPerPerspon[dislike[0]].Add(dislike[1]);
                if (!dislikesPerPerspon.ContainsKey(dislike[1]))
                {
                    dislikesPerPerspon.Add(dislike[1], new List<int>());
                }
                dislikesPerPerspon[dislike[1]].Add(dislike[0]);
            }

            foreach (KeyValuePair<int, List<int>> kvp in dislikesPerPerspon)
            {
                int person = kvp.Key;
                Console.WriteLine($"person: {person}");
                if (bipartitions[0].Contains(person) || bipartitions[1].Contains(person))
                {
                    Console.WriteLine("\talready checked");
                    continue;
                }

                int partition = 0;
                bipartitions[partition].Add(person);
                Console.WriteLine($"\tadding {person} to partition {partition}");
                Queue<int> queue = new Queue<int>(kvp.Value);
                Console.WriteLine($"\tadding [{string.Join(" ", kvp.Value)}] to queue");

                while (queue.Count > 0)
                {
                    int size = queue.Count;
                    for (int i = 0; i < size; i++)  // these people to be added to the other partition
                    {
                        int dislike = queue.Dequeue();
                        Console.WriteLine($"checking {dislike}");
                        if (bipartitions[partition].Contains(dislike))  // already disliked by someone in the other partition
                        {
                            Console.WriteLine($"\talready disliked by someone in the other partition");
                            return false;
                        }
                        if (bipartitions[1 - partition].Contains(dislike))  // already in the other partition
                        {
                            Console.WriteLine($"\talready in the other partition");
                            continue;
                        }
                        bipartitions[1 - partition].Add(dislike);
                        Console.WriteLine($"\tadding {dislike} to partition {1-partition}");
                        foreach (int nextDislike in dislikesPerPerspon[dislike])
                        {
                            if (bipartitions[0].Contains(nextDislike) || bipartitions[1].Contains(nextDislike))
                            {
                                continue;
                            }
                            queue.Enqueue(nextDislike);
                            Console.WriteLine($"\tadding [{nextDislike}] to queue, to be added to partition {partition}");
                        }
                    }
                    partition = 1 - partition;
                }   
            }
            return true;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int n = 4;
            int[][] dislikes = new int[][]
            {
                new int[] {1, 2},
                new int[] {1, 3},
                new int[] {2, 4}
            };
            Console.WriteLine(sol.PossibleBipartition(n, dislikes));    // true
            Console.WriteLine();

            n = 3;
            dislikes = new int[][]
            {
                new int[] {1, 2},
                new int[] {1, 3},
                new int[] {2, 3}
            };
            Console.WriteLine(sol.PossibleBipartition(n, dislikes));    // false
            Console.WriteLine();

            n = 5;
            dislikes = new int[][]
            {
                new int[] {1, 2},
                new int[] {2, 3},
                new int[] {3, 4},
                new int[] {4, 5},
                new int[] {5, 1}
            };
            Console.WriteLine(sol.PossibleBipartition(n, dislikes));    // false
            Console.WriteLine();
        }
    }
}
