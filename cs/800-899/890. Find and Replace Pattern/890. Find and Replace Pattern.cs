using System;
using System.Collections.Generic;

namespace _890.Find_and_Replace_Pattern
{
    public class Solution
    {
        public IList<string> FindAndReplacePattern(string[] words, string pattern)
        {
            List<string> r = new List<string>();
            foreach (string word in words)
            {
                Dictionary<char, char> mapChar = new Dictionary<char, char>();
                HashSet<char> setChar = new HashSet<char>();
                bool match = true;
                for (int i = 0; i < word.Length; i++)
                {
                    char c = word[i], p = pattern[i];
                    if (mapChar.ContainsKey(c))
                    {
                        if (mapChar[c] != p)
                        {
                            match = false;
                            break;
                        }
                    }
                    else if (setChar.Contains(p))
                    {
                        match = false;
                        break;
                    }
                    else
                    {
                        mapChar[c] = p;
                        setChar.Add(p);
                    }
                }
                if (match)
                {
                    r.Add(word);
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string[] words = new string[] { "abc", "deq", "mee", "aqq", "dkd", "ccc" };
            string pattern = "abb";
            IList<string> r = sol.FindAndReplacePattern(words, pattern);    // ["mee","aqq"]
            Console.WriteLine(string.Join(" ", r));

            words = new string[] { "a", "b", "c" };
            pattern = "a";
            r = sol.FindAndReplacePattern(words, pattern);  // ["a"]
            Console.WriteLine(string.Join(" ", r));
        }
    }
}
