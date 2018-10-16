//
//  599_Minimum_Index_Sum_of_Two_Lists.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/16/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> um1;
        for (int i = 0; i < list1.size(); i++) {
            um1[list1[i]] = i;
        }
        int least = INT_MAX;
        unordered_map<string,int> um2;
        for (int i = 0; i < list2.size(); i++) {
            if (um1.find(list2[i]) != um1.end()) {
                um2[list2[i]] = i + um1[list2[i]];
                least = min(least, um2[list2[i]]);
            }
        }
        vector<string> r;
        for (auto p: um2) {
            if (p.second == least) {
                r.push_back(p.first);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 599. Minimum Index Sum of Two Lists, C++ ...\n\n";
    Solution sol;

    vector<string> list1 {
        "Shogun", "Tapioca Express", "Burger King", "KFC"
    };
    vector<string> list2 {
        "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"
    };

    vector<string> r = sol.findRestaurant(list1, list2);
    for (string s: r) {
        cout << s << '\n';
    }

    return 0;
}
