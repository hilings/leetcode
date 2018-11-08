#   072
#   Edit Distance
#   2016-01-01
#####################################################
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = len(word1), len(word2)
        if not word1 or not word2:
            return l1 + l2
        d = [[None for j in range(l2)] for i in range(l1)]
        d[0][0] = 0 if word1[0] == word2[0] else 1

        for i in range(1, l1):
            d[i][0] = d[i-1][0] if (word1[i] == word2[0] and d[i-1][0] == i) else d[i-1][0]+1
        for j in range(1, l2):
            d[0][j] = d[0][j-1] if (word2[j] == word1[0] and d[0][j-1] == j) else d[0][j-1]+1
        for i in range(1, l1):
            for j in range(1, l2):
                d[i][j] = min([d[i-1][j], d[i][j-1]])
                if d[i-1][j-1] <= d[i][j]:
                    d[i][j] = d[i-1][j-1]
                    if word1[i] != word2[j]:
                        d[i][j] += 1
                else:
                    d[i][j] += 1
        for i in range(l1):
            for j in range(l2):
                print(d[i][j], end=' ')
            print()
        return d[l1-1][l2-1]

#####################################################
sol = Solution()

word1 = "XMJYAUZ"   #6
word2 = "MZJAWXU"
z = sol.minDistance(word1, word2)
print(z)

