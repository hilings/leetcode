using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _893.Groups_of_Special_Equivalent_Strings
{
    public class Solution
    {
        public int NumSpecialEquivGroups(string[] words)
        {
            HashSet<string> groups = new HashSet<string>();
            foreach (string word in words)
            {
                int[] countEven = new int[26], countOdd = new int[26];
                for (int i = 0; i < word.Length; i++)
                {
                    if (i % 2 == 0)
                    {
                        countEven[word[i] - 'a']++;
                    }
                    else
                    {
                        countOdd[word[i] - 'a']++;
                    }
                }
                groups.Add(string.Join(",", countEven) + string.Join(",", countOdd));
            }
            return groups.Count;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string[] words = new string[]
            {
                "abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"
            };
            int r = sol.NumSpecialEquivGroups(words); // 3
            Console.WriteLine(r);

            words = new string[]
            {
                "abc", "acb", "bac", "bca", "cab", "cba"
            };
            r = sol.NumSpecialEquivGroups(words); // 3
            Console.WriteLine(r);
        }
    }
}
