#   005
#   Longest Palindromic Substring
#####################################################
class Solution:
    # @return a string
    def longestPalindrome(self, s):
        slen = len(s)
        if slen <= 1:
            return s

        longest_start = 0
        longest_len = 1

        for i in range(1, slen):
            # palindrome even length
            p = i
            q = p - 1
            while q >= 0 and p < slen and s[q] == s[p]:
                p += 1
                q -= 1
            tlen = p - q - 1
            if tlen > longest_len:
                longest_start = q + 1
                longest_len = tlen

            # palindrome odd length
            p = i
            q = p - 2
            while q >= 0 and p < slen and s[q] == s[p]:
                p += 1
                q -= 1
            tlen = p - q - 1
            if tlen > longest_len:
                longest_start = q + 1
                longest_len = tlen
        return s[longest_start:longest_start+longest_len]

#####################################################

s = "";
s = "a";
s = "aa";
s = "ab";
s = "abc";
s = "abb";
s = "aba";
s = "aaa";
s = "forgeeksskeegfor";
s = "cabcbabcbabcba";
s = "habacdedcabag";
s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD";

print s

sol = Solution()
print sol.longestPalindrome(s)

