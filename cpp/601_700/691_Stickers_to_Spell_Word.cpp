//
//  691_Stickers_to_Spell_Word.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    int dfs(vector<unordered_set<string>>& coverage, vector<int>& target2, int n) {
        int i = 0;
        for ( ; i < 26; i++) {
            if (target2[i] > 0) {
                break;
            }
        }
        if (i == 26) {
            return n;
        }
        int z = INT_MAX;
        for (string word: coverage[i]) {
            for (char c: word) {
                target2[c-'a']--;
            }
            z = min(z, dfs(coverage, target2, n+1));
            for (char c: word) {
                target2[c-'a']++;
            }
        }
        return z;
    }
public:
    int minStickers0(vector<string>& stickers, string target) {     // dfs
        vector<int> target2 (26, 0);    // count of each char in target
        for (char c: target) {
            target2[c-'a']++;
        }
        vector<unordered_set<string>> coverage (26, unordered_set<string> {});  // stickers that cover each char
        for (string s: stickers) {
            for (char c: s) {
                coverage[c-'a'].insert(s);
            }
        }
        int z = 0;
        for (int i = 0; i < 26; i++) {      // check coverage for each char in target
            if (target2[i] <= 0) {
                continue;
            } else if (coverage[i].empty()) {     // char in target not covered by any sticker
                return -1;
            } else if (coverage[i].size() == 1) {  // preprocess, char c in target is covered by only one sticker
                string onlysticker = *coverage[i].begin();
                int k = target2[i];;
                z += k;
                for (char cc: onlysticker) {
                    target2[cc-'a'] -= k;
                }
            }
        }
        return dfs(coverage, target2, z);
    }

    int minStickers(vector<string>& stickers, string target) {      // dp with memoization
        int n = (int)stickers.size();
        unordered_map<string,int> dp;   // min for all string met
        vector<vector<int>> dict (n, vector<int> (26, 0));  // count of each char in each sticker
        for (int i = 0; i < n; i++) {       // each sticker
            for (char c: stickers[i]) {     // each char in sticker
                dict[i][c-'a']++;
            }
        }
        dp[""] = 0;     // init
        return helper(dict, dp, target);
    }

    int helper(vector<vector<int>>& dict, unordered_map<string,int>& dp, string target) {   // dp with memoization
        if (dp.find(target) != dp.end()) {
            return dp[target];
        }
        vector<int> target2 (26, 0);
        for (char c: target) {  // count each char in target
            target2[c-'a']++;
        }
        int z = INT_MAX;
        for (vector<int>& word: dict) {  // try to apply each word on target
            if (word[target[0]-'a'] == 0) {     // this word does not cover first char target[0]
                continue;
            }
            string next = "";
            for (int i = 0; i < 26; i++) {
                next += string(max(target2[i] - word[i], 0), 'a'+i);    // serialize target string for dp memoization
            }
            int t = helper(dict, dp, next);
            if (t != -1) {
                z = min(z, t+1);
            }
        }
        dp[target] = z == INT_MAX ? -1 : z;
        return dp[target];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 691. Stickers to Spell Word, C++ ...\n\n";
    Solution sol;

    vector<string> stickers {
        "with", "example", "science"
        /*
         "heavy","claim","seven","set","had","it","dead","jump","design","question",
         "sugar","dress","any","special","ground","huge","use","busy","prove","there",
         "lone","window","trip","also","hot","choose","tie","several","be","that",
         "corn","after","excite","insect","cat","cook","glad","like","wont","gray",
         "especially","level","when","cover","ocean","try","clean","property","root","wing"
         */
    };
    string target = "thehat";
    //target = "travelbell";

    int r0 = sol.minStickers0(stickers, target);
    cout << r0 << '\n';

    int r = sol.minStickers(stickers, target);
    cout << r << '\n';

    return 0;
}
