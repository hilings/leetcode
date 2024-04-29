using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _884.Uncommon_Words_from_Two_Sentences
{
    public class Solution
    {
        public string[] UncommonFromSentences(string s1, string s2)
        {
            Dictionary<string, int> dict1 = new Dictionary<string, int>(), dict2 = new Dictionary<string, int>();
            s1.Split(' ').ToList().ForEach(word => dict1[word] = dict1.ContainsKey(word) ? dict1[word] + 1 : 1);
            s2.Split(' ').ToList().ForEach(word => dict2[word] = dict2.ContainsKey(word) ? dict2[word] + 1 : 1);

            List<string> words = new List<string>();
            foreach (KeyValuePair<string, int> wordCount in dict1)
            {
                if (wordCount.Value == 1 && !dict2.ContainsKey(wordCount.Key))
                {
                    words.Add(wordCount.Key);
                }
            }
            foreach (KeyValuePair<string, int> wordCount in dict2)
            {
                if (wordCount.Value == 1 && !dict1.ContainsKey(wordCount.Key))
                {
                    words.Add(wordCount.Key);
                }
            }
            return words.ToArray();
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string s1 = "this apple is sweet";
            string s2 = "this apple is sour";
            Console.WriteLine(string.Join(", ", sol.UncommonFromSentences(s1, s2)));   // sweet, sour
            Console.WriteLine();

            s1 = "apple apple";
            s2 = "banana";
            Console.WriteLine(string.Join(", ", sol.UncommonFromSentences(s1, s2)));   // banana
            Console.WriteLine();
        }
    }
}
