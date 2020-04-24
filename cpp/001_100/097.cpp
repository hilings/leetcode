//
//  097.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t n1 = s1.size(), n2 = s2.size();
        if (n1+n2 != s3.size())
            return false;
        bool m[n1+1][n2+1];
        m[0][0] = true;
        for (int i = 1; i <= n1; i++)
            m[i][0] = m[i-1][0] && (s1[i-1] == s3[i-1]);
        for (int j = 1; j <= n2; j++)
            m[0][j] = m[0][j-1] && (s2[j-1] == s3[j-1]);
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                m[i][j] = (m[i-1][j] && (s1[i-1] == s3[i+j-1])) || (m[i][j-1] && (s2[j-1] == s3[i+j-1]));
        return m[n1][n2];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 097 Interleaving String, C++ ...\n\n";
    Solution sol;

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    //s3 = "aadbbbaccc";

    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    
    bool r = sol.isInterleave(s1, s2, s3);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}