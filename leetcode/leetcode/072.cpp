//
//  072.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/23/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty())
            return (int)(word1.size() + word2.size());

        //int m[word1.size()][word2.size()];
        int d[word1.size()][word2.size()];
        //m[0][0] = word1[0] == word2[0] ? 1 : 0;
        d[0][0] = word1[0] == word2[0] ? 0 : 1;

        for (int i = 1; i < word1.size(); i++) {
            //m[i][0] = (word1[i] == word2[0] || m[i-1][0] == 1) ? 1 : 0;
            d[i][0] = (word1[i] == word2[0] && d[i-1][0] == i) ? d[i-1][0] : d[i-1][0]+1;
        }
        for (int j = 1; j < word2.size(); j++) {
            //m[0][j] = (word2[j] == word1[0] || m[0][j-1] == 1) ? 1 : 0;
            d[0][j] = (word2[j] == word1[0] && d[0][j-1] == j) ? d[0][j-1] : d[0][j-1]+1;
        }
        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                /*
                m[i][j] = max(m[i-1][j], m[i][j-1]);
                if (word1[i] == word2[j])
                    m[i][j] = max(m[i][j], m[i-1][j-1]+1);
                 */

                d[i][j] = min(d[i-1][j], d[i][j-1]);
                if (d[i-1][j-1] <= d[i][j]) {
                    d[i][j] = d[i-1][j-1];
                    if (word1[i] != word2[j])
                        d[i][j]++;
                } else
                    d[i][j]++;
            }
        }

        /*
        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                cout << m[i][j] << "  ";
            }
            cout << '\n';
        }
        cout << "\n";
         */

        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                cout << d[i][j] << "  ";
            }
            cout << '\n';
        }
        return d[word1.size()-1][word2.size()-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 072 Edit Distance, C++ ...\n\n";
    Solution sol;

    string word1 = "XMJYAUZ";   //6
    string word2 = "MZJAWXU";
    word1 = "zoologicoarchaeologist";   //10
    word2 = "zoogeologist";
    word1 = "mart";   //3
    word2 = "karma";

    int r = sol.minDistance(word1, word2);
    cout << "r = " << r << '\n';
    
    return 0;
}
