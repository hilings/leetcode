//
//  host.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/22/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    vector<string> paginate(int resultsPerPage, vector<string> results) {
        vector<string> r;
        vector<bool> visited (results.size(), false);
        int m = 0;
        int start = 0;
        bool update = true;
        while (m < results.size()) {
            unordered_set<int> us {};
            int count = 0;
            for (int i = start; i < results.size() && count < resultsPerPage; i++) {
                if (visited[i]) {
                    continue;
                }
                string line = results[i];
                string::size_type pos = line.find(',');
                int host_id = stoi(line.substr(0, pos));
                if (us.find(host_id) == us.end()) {
                    r.push_back(line);
                    us.insert(host_id);
                    visited[i] = true;
                    count++;
                    m++;
                    if (update) {
                        start = i+1;
                    }
                } else {
                    update = false;
                }
            }
            for (int i = start; i < results.size() && count < resultsPerPage; i++) {
                if (visited[i]) {
                    continue;
                }
                r.push_back(results[i]);
                visited[i] = true;
                count++;
                m++;
                start = i+1;
            }
            if (count == resultsPerPage) {
                r.push_back("");
            }
        }
        return r;
    }

    vector<string> paginate2(int resultsPerPage, vector<string> results) {
        unordered_map<int,deque<int>> um;   // host_id => [indices]
        for (int i = 0; i < results.size(); i++) {
            string::size_type pos = results[i].find(',');
            int id = stoi(results[i].substr(0, pos));
            if (um.find(id) == um.end()) {
                um[id] = deque<int> {};
            }
            um[id].push_back(i);
        }
        vector<string> r;

        auto cmp = [&um] (const int& id1, const int& id2) {
            return um[id1][0] > um[id2][0];
        };
        while (!um.empty()) {
            if (um.size() >= resultsPerPage) {  // enough unique host_id for one page
                priority_queue<int,vector<int>, decltype(cmp)> cand (cmp);    // heap of host_ids, sorted by their first index
                for (auto p: um) {
                    cand.push(p.first);
                }
                for (int i = 0; i < resultsPerPage; i++) {
                    int id = cand.top(); // host whose first index is smallest
                    cand.pop();     // no refill
                    r.push_back(results[um[id][0]]);
                    um[id].pop_front();
                    if (um[id].empty()) {
                        um.erase(id);
                    }
                }
            } else {    // not enough unique host_id for one page,
                priority_queue<int,vector<int>, decltype(cmp)> cand (cmp);    // heap of host_ids, sorted by their first index

                // first step, pick one for each unique host
                for (auto p: um) {
                    cand.push(p.first);
                }
                while (!cand.empty()) {
                    int id = cand.top();
                    cand.pop();     // no refill
                    r.push_back(results[um[id][0]]);
                    um[id].pop_front();
                    if (um[id].empty()) {
                        um.erase(id);
                    }
                }

                // second step, pad with duplicated host
                for (auto p: um) {
                    cand.push(p.first);
                }
                while (r.size() % (resultsPerPage+1) < resultsPerPage && !cand.empty()) {
                    int id = cand.top();
                    cand.pop();
                    r.push_back(results[um[id][0]]);
                    um[id].pop_front();
                    if (!um[id].empty()) {
                        cand.push(id);  // keep refill
                    } else {
                        um.erase(id);
                    }
                }
            }

            if (!um.empty()) {  // there will be next page
                r.push_back("");
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    /*
     try to fill [resultsPerPage] lines the page with unique host_id
     if not enough unique host_id, then fill page with duplicated host
     */
    Solution sol;

    int resultsPerPage = 5;
    vector<string> results = {
               "1,28,300.6,San Francisco",
               "4,5,209.1,San Francisco",
               "20,7,203.4,Oakland",
               "6,8,202.9,San Francisco",
               "6,10,199.8,San Francisco",
               "1,16,190.5,San Francisco",
               "6,29,185.3,San Francisco",
               "7,20,180.0,Oakland",
               "6,21,162.2,San Francisco",
               "2,18,161.7,San Jose",
               "2,30,149.8,San Jose",
               "3,76,146.7,San Francisco",
               "2,14,141.8,San Jose"
    };

    /*
     "1,28,300.6,San Francisco",
     "4,5,209.1,San Francisco",
     "20,7,203.4,Oakland",
     "6,8,202.9,San Francisco",
     "7,20,180.0,Oakland",
     "", # this is a page separator
     "6,10,199.8,San Francisco",
     "1,16,190.5,San Francisco",
     "2,18,161.7,San Jose",
     "3,76,146.7,San Francisco",
     "6,29,185.3,San Francisco",
     "", # this is a page separator
     "6,21,162.2,San Francisco",
     "2,30,149.8,San Jose",
     "2,14,141.8,San Jose"]
     */

    vector<string> r = sol.paginate(resultsPerPage, results);
    for (string s: r) {
        cout << s << '\n';
    }
    cout << '\n';

    vector<string> r2 = sol.paginate2(resultsPerPage, results);
    for (string s: r2) {
        cout << s << '\n';
    }

    return 0;
}
