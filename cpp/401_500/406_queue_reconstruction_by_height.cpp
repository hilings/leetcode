//
//  406_queue_reconstruction_by_height.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/28/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<pair<int, int>> reconstructQueue0(vector<pair<int, int>>& people) {
        vector<pair<int,int>> r (people);
        auto cmp = [] (const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        };
        sort(r.begin(), r.end(), cmp);
        for (int i = 1, j, k; i < r.size(); i++) {
            //printf("checking [%d, %d]\n", r[i].first, r[i].second);
            if (r[i].second == 0) {
                continue;
            }
            for (j = 0, k = r[i].second; j < i && k >= 0; j++) {
                if (r[j].first >= r[i].first) {
                    k--;
                }
                if (k < 0) {
                    break;
                }
            }
            //printf("pos = %d\n", j);
            pair<int,int> p = r[i];
            r.erase(r.begin()+i);
            r.insert(r.begin()+j, p);

            /*
             for (pair<int,int> p: r) {
             printf("[%d, %d]\n", p.first, p.second);
             }
             cout << '\n';
             */
        }
        return r;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> r;
        auto cmp = [] (const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        sort(people.begin(), people.end(), cmp);
        for (pair<int,int> p: people) {
            r.insert(r.begin() + p.second, p);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 406. Queue Reconstruction by Height, C++ ...\n\n";
    Solution sol;

    vector<pair<int,int>> people {
        {7,0},{4,4},{7,1},{5,0},{6,1},{5,2}	// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    };
    
    vector<pair<int,int>> r0 = sol.reconstructQueue0(people);
    for (pair<int,int> p: r0) {
        printf("[%d, %d], ", p.first, p.second);
    }
    cout << '\n';
    
    vector<pair<int,int>> r = sol.reconstructQueue(people);
    for (pair<int,int> p: r) {
        printf("[%d, %d], ", p.first, p.second);
    }
    cout << '\n';
    
    return 0;
}
