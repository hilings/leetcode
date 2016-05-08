//
//  218.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> ret {pair<int,int> (-1,0)};
        for (vector<int> b: buildings) {
            for (int i = 0; i < ret.size()-1 && b[0] < b[1]; i++) {
                if (ret[i+1].first <= b[0])
                    continue;
                vector<int> tb (b);
                if (ret[i+1].first <= b[1]) {
                    tb[1] = ret[i+1].first;
                    b[0] = ret[i+1].first;
                } else {
                    b[0] = b[1];
                }
                //cout << "building: (" << tb[0] << ", " << tb[1] << ", " << tb[2] << ")\n";

                if (tb[2] > ret[i].second) {
                    if (tb[1] < ret[i+1].first) {
                        ret.insert(ret.begin()+i+1, pair<int,int> (tb[1], ret[i].second));
                        //cout << "inserting ... ( " << tb[1] << ", " << ret[i].second << " )\n";
                    }

                    if (ret[i].first < tb[0]) {
                        ret.insert(ret.begin()+i+1, pair<int,int> (tb[0], tb[2]));
                        //cout << "inserting ... ( " << tb[0] << ", " << tb[2] << " )\n";
                    } else {
                        ret[i].second = tb[2];
                        //cout << "... elevated\n";
                    }
                } else {
                    //cout << "... covered\n";
                }
            }
            if (b[0] < b[1]) {
                if (ret.back().first < b[0])
                    ret.push_back(pair<int,int> (b[0], b[2]));
                else
                    ret.back().second = b[2];
                ret.push_back(pair<int,int> (b[1], 0));
            }
        }
        vector<pair<int,int>> ret2;
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i].second == ret[i-1].second)
                continue;
            ret2.push_back(ret[i]);
        }
        return ret2;
    }

    vector<pair<int, int>> getSkyline2(vector<vector<int>>& buildings) {
        list<pair<int,int>> l {pair<int,int> (-1,0)};
        for (vector<int> b: buildings) {
            for (list<pair<int,int>>::iterator it = l.begin(); it != prev(l.end()) && b[0] < b[1]; it++) {
                if (next(it)->first <= b[0])
                    continue;
                vector<int> tb (b);
                if (next(it)->first <= b[1]) {
                    tb[1] = next(it)->first;
                    b[0] = next(it)->first;
                } else {
                    b[0] = b[1];
                }
                //cout << "building: (" << tb[0] << ", " << tb[1] << ", " << tb[2] << ")\n";

                if (tb[2] > it->second) {
                    if (tb[1] < next(it)->first) {
                        l.insert(next(it), pair<int,int> (tb[1], it->second));
                        //cout << "inserting ... ( " << tb[1] << ", " << it->second << " )\n";
                    }

                    if (it->first < tb[0]) {
                        l.insert(next(it), pair<int,int> (tb[0], tb[2]));
                        //cout << "inserting ... ( " << tb[0] << ", " << tb[2] << " )\n";
                    } else {
                        it->second = tb[2];
                        //cout << "... elevated\n";
                    }
                } else {
                    //cout << "... covered\n";
                }
            }
            if (b[0] < b[1]) {
                if (l.back().first < b[0])
                    l.push_back(pair<int,int> (b[0], b[2]));
                else
                    l.back().second = b[2];
                l.push_back(pair<int,int> (b[1], 0));
            }
        }
        vector<pair<int,int>> ret;
        for (list<pair<int,int>>::iterator it = next(l.begin()); it != l.end(); it++) {
            if (it->second == prev(it)->second)
                continue;
            ret.push_back(*it);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 218. The Skyline Problem, C++ ...\n\n";
    Solution sol;
    
    vector<vector<int>> buildings {
        vector<int> {2, 9, 10}
        ,vector<int> {3, 7, 15}
        ,vector<int> {5, 12, 12}
        ,vector<int> {15, 20, 10}
        ,vector<int> {19, 24, 8}
        
        /*
         [2 10],
         [3 15],
         [7 12],
         [12 0],
         [15 10],
         [20 8],
         [24, 0]
         */
    };
    
    vector<pair<int,int>> r = sol.getSkyline2(buildings);
    for (pair<int,int> p: r) {
        cout << "[ " << p.first << ", " << p.second << " ]\n";
    }
    
    return 0;
}