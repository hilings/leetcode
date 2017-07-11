//
//  420_strong_password_checker.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/11/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = (int)s.size(), count = 0, miss = s.find_first_of("0123456789") == string::npos ? 1 : 0;
        miss += s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos ? 1 : 0;
        miss += s.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos ? 1 : 0;
        vector<vector<int>> rep (3, vector<int> {});
        printf("%s, n = %d, miss = %d\n", s.c_str(), (int)s.size(), miss);

        for (int i = 0; i < n-2; ) {
            if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
                if (n < 6) {
                    n++;	// insert missing char
                    miss -= miss > 0 ? 1 : 0;
                    count++;
                    i += 3;
                } else if (n <= 20) {
                    miss -= miss > 0 ? 1 : 0;	// replace missing char
                    count++;
                    i += 3;
                } else {
                    int j = i;
                    while (i < n && s[i] == s[j]) {
                        i++;
                    }
                    int len = i-j;
                    rep[len%3].push_back(len);	// save for later to delete
                }
            } else {
                i++;
            }
        }

        if (n <= 20) {	// if n <= 20, by now there will be no repetition
            count += max(miss, 6-n);	// insert if too short, or replace if miss char, whichever is more
            return count;
        }

        for (int k = 0; k <= 2 && n > 20; k++) {	// delete repetition if too long due to repetition
            while (!rep[k].empty() && n > 20) {
                int l = rep[k].back(), d = min(l%3+1, n-20);	// delete l%3+1 char or until n = 20, whichever is less
                rep[k].pop_back();
                count += d;
                l -= d;
                if (l >= 3) {
                    rep[l%3].push_back(l);
                }
                n -= d;
            }
        }	// so far string will not be too long due to repetition

        for (int k = 0; k <= 2; k++) {	// replace every 3rd char of each repetition
            for (int l: rep[k]) {
                count += l/3;	// replace every 3rd char
                miss -= min(miss, l/3);
            }
        }
        count += max(n-20, 0) + miss;
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 420. Strong Password Checker, C++ ...\n\n";
    Solution sol;

    string s = "ABABABABABABABABABAB1";	// 2
    cout << sol.strongPasswordChecker(s) << "\n\n";

    s = "";	// 6
    cout << sol.strongPasswordChecker(s) << "\n\n";

    s = "aaaabbaaabbaaa123456A";	// 3
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "aaaaaaaaaaaaaaaaaaaaa";	// 7
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "..................!!!";	// 7
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "1Abababcaaaabababababa";	// 2
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "ababababababababaaaaa";	// 3
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "aaaaabbbb1234567890ABA";	// 3
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    s = "aaaaaaaAAAAAA6666bbbbaaaaaaABBC";	// 13
    cout << sol.strongPasswordChecker(s) << "\n\n";
    
    return 0;
}
