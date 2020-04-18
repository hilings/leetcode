//
//  721_Accounts_Merge.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/16/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

// #include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> r;
        unordered_map<string, vector<set<string>>> um; // map: name => vector of sets of emails

        for (auto v : accounts) {
            string name = v[0];
            set<string> emails(v.begin() + 1, v.end());

            int flag = 0;
            for (int i = 0; i < um[name].size(); i++) { // loop through sets of emails under this name
                if (!hasInteraction(emails, um[name][i])) {
                    continue;
                }

                int countBefore = (int)um[name][i].size();
                um[name][i].insert(emails.begin(), emails.end()); // merge current emails into the one having intersection
                if (um[name][i].size() > countBefore) {           // introducing new email
                    flag = 1;
                    swap(um[name][0], um[name][i]); // swap to first position
                } else {                            // no new email
                    flag = 2;
                }
                break;
            }

            // merge any potential intersection
            switch (flag) {
            case 0: // new email introduced, no potential merge
                um[name].push_back(emails);
                break;
            case 1: // new email introduced, potential merge
                for (int i = 1; i < um[name].size();) {
                    if (hasInteraction(um[name][i], um[name][0])) {
                        um[name][0].insert(um[name][i].begin(), um[name][i].end());
                        swap(um[name][i], um[name][um[name].size() - 1]);
                        um[name].pop_back();
                    } else {
                        i++;
                    }
                }
                break;
            case 2: // just repeated email, do nothing
                break;
            }
        }

        for (auto p : um) {
            for (auto v : p.second) {
                vector<string> account{p.first};
                account.insert(account.begin() + 1, v.begin(), v.end());
                r.push_back(account);
            }
        }

        return r;
    }

    bool hasInteraction(set<string> &s1, set<string> &s2) {
        for (auto s : s1) {
            if (s2.find(s) != s2.end()) {
                return true;
            }
        }
        return false;
    }

    vector<vector<string>> accountsMerge2(vector<vector<string>> &accounts) {
        unordered_map<string, set<string>> um_email_neighbors; // map: email => set of emails that belong to same person
        unordered_map<string, string> um_email_name;           // map: email => name
        for (auto v : accounts) {
            string name = v[0];
            for (int i = 1; i < v.size(); i++) {
                um_email_neighbors[v[i]].insert(v[1]); // only need to connect to first email
                um_email_neighbors[v[1]].insert(v[i]); // no need to connect to every single neighbor
                um_email_name[v[i]] = name;
            }
        }

        vector<vector<string>> r;
        unordered_set<string> visited;
        for (auto p : um_email_neighbors) {
            string email = p.first;
            if (visited.find(email) != visited.end()) {
                continue;
            }
            vector<string> q(p.second.begin(), p.second.end());
            set<string> emails{email};
            while (!q.empty()) { // DFS, traverse connected emails
                string e = q.back();
                q.pop_back();
                if (visited.find(e) != visited.end()) {
                    continue;
                }
                emails.insert(e);
                for (auto nb : um_email_neighbors[e]) {
                    if (visited.find(nb) == visited.end()) {
                        q.push_back(nb);
                    }
                }
                visited.insert(e);
            }
            vector<string> account{um_email_name[email]};
            account.insert(account.end(), emails.begin(), emails.end());
            r.push_back(account);
        }

        return r;
    }

    vector<vector<string>> accountsMerge3(vector<vector<string>> &accounts) {
        unordered_map<string, string> um_email_parent; // map: email => parent
        unordered_map<string, string> um_email_name;   // map: email => name
        for (auto v : accounts) {
            for (int i = 1; i < v.size(); i++) {
                um_email_parent[v[i]] = v[i];
                um_email_name[v[i]] = v[0];
            }
        }

        for (auto v : accounts) {
            string p = find_parent_recursive(um_email_parent, v[1]);
            for (int i = 2; i < v.size(); i++) {
                um_email_parent[find_parent_recursive(um_email_parent, v[i])] = p; // update parent recursively
            }
        }

        unordered_map<string, set<string>> um_email_set; // map: email => set of emails that belong to same person
        for (auto v : accounts) {
            for (int i = 1; i < v.size(); i++) {
                string p = find_parent_recursive(um_email_parent, v[i]);
                um_email_set[p].insert(v[i]);
            }
        }

        vector<vector<string>> r;
        for (auto p : um_email_set) {
            vector<string> account{um_email_name[p.first]};
            account.insert(account.end(), p.second.begin(), p.second.end());
            r.push_back(account);
        }

        return r;
    }

    string find_parent_recursive(unordered_map<string, string> &um, string e) {
        return um[e] == e ? e : find_parent_recursive(um, um[e]);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 721. Accounts Merge, C++ ...\n\n";
    Solution sol;

    vector<vector<string>> accounts{
        // {"John", "johnsmith@mail.com", "john00@mail.com"},
        // {"John", "johnnybravo@mail.com"},
        // {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        // {"Mary", "mary@mail.com"}

        {"Ethan", "Ethan1@m.co", "Ethan2@m.co", "Ethan0@m.co"},
        {"David", "David1@m.co", "David2@m.co", "David0@m.co"},
        {"Lily", "Lily0@m.co", "Lily0@m.co", "Lily4@m.co"},
        {"Gabe", "Gabe1@m.co", "Gabe4@m.co", "Gabe0@m.co"},
        {"Ethan", "Ethan2@m.co", "Ethan1@m.co", "Ethan0@m.co"}

    };

    vector<vector<string>> r = sol.accountsMerge(accounts);

    for (auto v : r) {
        for (auto s : v) {
            cout << s << ", ";
        }
        cout << '\n';
    }
    cout << '\n';

    r = sol.accountsMerge2(accounts);

    for (auto v : r) {
        for (auto s : v) {
            cout << s << ", ";
        }
        cout << '\n';
    }
    cout << '\n';

    r = sol.accountsMerge3(accounts);

    for (auto v : r) {
        for (auto s : v) {
            cout << s << ", ";
        }
        cout << '\n';
    }

    return 0;
}
