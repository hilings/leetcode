#   049
#   Group Anagrams
#   2015-09-10
#####################################################
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dict = {}
        for word in strs:
            key = ''.join(sorted(word))
            if key not in dict:
                dict[key] = []
            dict[key].append(word)
        for key in dict:
            dict[key] = sorted(dict[key])
        return dict.values()

#####################################################

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

sol = Solution()

print sol.groupAnagrams(strs)

