//
//  692_Top_K_Frequent_Words.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> z;
        unordered_map<string,int> um;
        for (string w: words) {
            if (um.find(w) == um.end()) {
                um[w] = 0;
            }
            um[w]++;
        }
        auto cmp = [] (const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq (cmp);
        for (pair<string,int> p: um) {
            pq.push(p);
        }
        for (int i = 0; i < k; i++) {
            z.push_back(pq.top().first);
            pq.pop();
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 692. Top K Frequent Words, C++ ...\n\n";
    Solution sol;

    vector<string> words {
        "i", "love", "leetcode", "i", "love", "coding"
    };
    int k = 2;

    vector<string> z = sol.topKFrequent(words, k);
    for (string s: z) {
        cout << s << '\n';
    }

    return 0;
}
