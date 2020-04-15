//
//  715_Range_Module.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/22/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RangeModule {
    vector<pair<int,int>> v;
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        pair<int,int> pit = locate(left, right);
        int lower = pit.first, upper = pit.second;

        left = lower < v.size() ? min(left, v[lower].first) : left;
        right = upper-1 >= 0 ? max(right, v[upper-1].second) : right;
        if (lower != upper) {
            v.erase(v.begin()+lower, v.begin()+upper);
        }
        v.insert(v.begin()+lower, {left,right});

        p();
    }

    bool queryRange(int left, int right) {
        pair<int,int> pit = locate(left, right);
        int lower = pit.first, upper = pit.second;
        if (lower == v.size() || upper == 0) {
            return false;
        }
        return v[lower].first <= left && v[lower].second >= right;
    }

    void removeRange(int left, int right) {
        pair<int,int> pit = locate(left, right);
        int lower = pit.first, upper = pit.second;
        if (lower == v.size() || upper == 0) {
            return;
        }
        vector<pair<int,int>> pending;
        if (v[lower].first < left) {
            pending.push_back({v[lower].first, left});
        }
        if (right < v[upper-1].second) {
            pending.push_back({right, v[upper-1].second});
        }
        v.erase(v.begin()+lower, v.begin()+upper);
        v.insert(v.begin()+lower, pending.begin(), pending.end());

        p();
    }

    pair<int,int> locate(int left, int right) { // locate nearby ranges
        auto cmp1 = [](pair<int,int> a, pair<int,int> b) { return a.second < b.second; };
        vector<pair<int,int>>::iterator lower = lower_bound(v.begin(), v.end(), pair<int,int>{left,left}, cmp1);
        auto cmp2 = [](pair<int,int> a, pair<int,int> b) { return a.first < b.first; };
        vector<pair<int,int>>::iterator upper = upper_bound(v.begin(), v.end(), pair<int,int>{right,right}, cmp2);

        return {lower - v.begin(), upper - v.begin()};
    }

    void p() {
        for (auto p: v) {
            printf("(%d, %d)\n", p.first, p.second);
        }
        cout << '\n';
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 715. Range Module, C++ ...\n\n";

    RangeModule* obj = new RangeModule();

    obj->addRange(10,20);

    obj->removeRange(14,16);

    cout << (obj->queryRange(10,14) ? "true" : "false") << '\n';
    cout << (obj->queryRange(13,15) ? "true" : "false") << '\n';
    cout << (obj->queryRange(16,17) ? "true" : "false") << '\n';


    return 0;
}
