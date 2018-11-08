#   005
#   Longest Palindromic Substring
#####################################################
#   central expansion
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
#   Manacher's algorithm
class Solution2:
    # @param s, a string
    # @return a string
    def longestPalindrome(self, s):
        slen = len(s)
        if slen <= 1:
            return s

        T = "^#"
        for c in s:
            T += c + "#"
        T += "$"

        tlen = len(T)
        P = [0 for i in range(tlen)]
        C = 0
        R = 0
        maxC = 0
        for i in range(1, tlen - 1):
            P[i] = 0 if i >= R else min(R-i, P[2*C-i])
            while T[i+P[i]+1] == T[i-P[i]-1]:
                P[i] += 1
            if i + P[i] > R:
                C = i
                R = i + P[i]
                if P[i] > P[maxC]:
                    maxC = i
        start = (maxC-P[maxC]-1)//2
        return s[start:start+P[maxC]]
        
#####################################################

s = "forgeeksskeegfor"
#s = "cabcbabcbabcba"
#s = "habacdedcabag"
#s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD"
#s = "aba"

print(s)

sol = Solution2()
z = sol.longestPalindrome(s)
print(z)

