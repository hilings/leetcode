//
//  332.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ret {"JFK"};
        unordered_map<string,vector<string>> um;	// vector
        for (auto t: tickets) {
            um[t.first].push_back(t.second);
        }
        for (auto &p: um) {
            sort(p.second.begin(), p.second.end());
        }
        for (int i = 0; ret.size() <= tickets.size(); ) {
            string cur = ret[i];
            if (um[cur].empty()) {
                i--;
            } else {
                ret.insert(ret.begin()+i+1, um[cur].front());
                um[cur].erase(um[cur].begin());
                i++;
            }
        }
        return ret;
    }

    vector<string> findItinerary2(vector<pair<string, string>> tickets) {	// iterative
        vector<string> ret {"JFK"};
        unordered_map<string,multiset<string>> um;	// multiset
        for (auto t: tickets) {
            um[t.first].insert(t.second);
        }
        for (int i = 0; ret.size() <= tickets.size(); ) {
            string cur = ret[i];
            if (um[cur].empty()) {
                i--;
            } else {
                ret.insert(ret.begin()+i+1, *(um[cur].begin()));
                um[cur].erase(um[cur].begin());
                i++;
            }
        }
        return ret;
    }

    vector<string> findItinerary3(vector<pair<string, string>> tickets) {	// recursive
        vector<string> ret;
        unordered_map<string,multiset<string>> um;	// multiset
        for (auto t: tickets) {
            um[t.first].insert(t.second);
        }
        solve(um, ret, "JFK");
        return vector<string> (ret.rbegin(), ret.rend());
    }
    void solve(unordered_map<string,multiset<string>> &um, vector<string> &ret, string cur) {
        while (!um[cur].empty()) {
            string next = *um[cur].begin();
            um[cur].erase(um[cur].begin());
            solve(um, ret, next);
        }
        ret.push_back(cur);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 332. Reconstruct Itinerary, C++ ...\n\n";
    Solution sol;

    vector<pair<string,string>> tickets {
        /*
         pair<string,string> ("MUC", "LHR"),
         pair<string,string> ("JFK", "MUC"),
         pair<string,string> ("SFO", "SJC"),
         pair<string,string> ("LHR", "SFO")
         //["JFK", "MUC", "LHR", "SFO", "SJC"]
         */

        /*
         pair<string,string> ("JFK","SFO"),
         pair<string,string> ("JFK","ATL"),
         pair<string,string> ("SFO","ATL"),
         pair<string,string> ("ATL","JFK"),
         pair<string,string> ("ATL","SFO")
         //["JFK","ATL","JFK","SFO","ATL","SFO"]
         */
        
        //*
        pair<string,string> ("JFK","KUL"),
        pair<string,string> ("JFK","NRT"),
        pair<string,string> ("NRT","JFK")
        //["JFK","NRT","JFK","KUL"]
        //*/
    };
    
    vector<string> r = sol.findItinerary(tickets);
    for (string s: r) {
        cout << s << " -> ";
    }
    cout << '\n';
    
    vector<string> r2 = sol.findItinerary2(tickets);
    for (string s: r2) {
        cout << s << " -> ";
    }
    cout << '\n';
    
    vector<string> r3 = sol.findItinerary3(tickets);
    for (string s: r3) {
        cout << s << " -> ";
    }
    
    return 0;
}
