#   068
#   Test Justification
#   2015-12-22
#####################################################
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        v, line = [], []
        for word in words:
            if len(' '.join(line+[word])) > maxWidth:
                v.append(self.joinLine(line, maxWidth))
                line = []
            line.append(word)
        v.append(self.joinLine(line, maxWidth, True))
        return v

    def joinLine(self, line, maxWidth, last = False):
        if (len(line) == 1 or last == True):
            return ' '.join(line) + ' '*(maxWidth - len(' '.join(line)))
        space, extra = divmod(maxWidth - len(''.join(line)), len(line)-1)
        return (' '*(space+1)).join(line[:extra+1]) + ' '*space + (' '*space).join(line[extra+1:])

#####################################################
sol = Solution()

words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
r = sol.fullJustify(words, maxWidth)

for word in r:
    print '"'+word+'"'

