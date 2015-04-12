#   003
#   Longest Substring Without Repeating Characters
#####################################################
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        longest = 0
        tmp = 0
        head = 0
        tail = 0
        length = len(s)
        while tail < length:
            c = s[tail]
            index = s.find(c, head, tail)
            if index == -1:
                tmp += 1
            elif index == head:
                head += 1
            else:
                if tmp > longest:
                    longest = tmp
                head = index + 1
                tmp = tail - head + 1
            tail += 1
            print head, tail, s[head:tail]
        if tmp > longest:
            longest = tmp
        return longest

#####################################################

s = "epqcrkeyjzbkvkrganbg"
print s

sol = Solution()
print sol.lengthOfLongestSubstring(s)



