//
//  399_evaluate_division.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/21/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,	vector<double>& values,	vector<pair<string, string>> queries) {
        // graph, path weight from one vertex to another
        unordered_map<string,unordered_map<string,double>> edges;
        for (int i = 0; i < equations.size(); i++) {
            pair<string,string> e = equations[i];
            if (edges.find(e.first) == edges.end()) {
                edges[e.first] = unordered_map<string,double> {};
            }
            edges[e.first][e.second] = values[i];
            if (edges.find(e.second) == edges.end()) {
                edges[e.second] = unordered_map<string,double> {};
            }
            edges[e.second][e.first] = 1/values[i];
        }

        /*
        cout << "all edges:\n";
        for (pair<string,unordered_map<string,double>> e: edges) {
            for (pair<string,double> w: e.second) {
                printf("%s -> %s = %f\n", e.first.c_str(), w.first.c_str(), w.second);
            }
        }
        cout << '\n';
         */

        vector<double> r;
        for (pair<string,string> q: queries) {
            if (edges.find(q.first) == edges.end() || edges.find(q.second) == edges.end()) {
                r.push_back(-1.0);
            } else {
                unordered_set<string> tovisit {q.first};
                unordered_map<string,double> dist {pair<string,double> (q.first, 1.0)};

                while (!tovisit.empty()) {
                    if (dist.find(q.second) != dist.end()) {
                        break;
                    }

                    string cur = *(tovisit.begin());
                    //printf("visiting %s\n", cur.c_str());
                    tovisit.erase(cur);

                    for (pair<string,double> e: edges[cur]) {
                        if (dist.find(e.first) != dist.end()) {	// visited
                            continue;
                        }
                        dist[e.first] = dist[cur] * e.second;
                        //printf("reaching %s by %f\n", e.first.c_str(), dist[e.first]);
                        tovisit.insert(e.first);	// tovisit
                    }
                }
                r.push_back(dist.find(q.second) == dist.end() ? -1.0 : dist[q.second]);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 399. Evaluate Division, C++ ...\n\n";
    Solution sol;
    
    vector<pair<string,string>> equations {
        pair<string,string> ("a", "b"),
        pair<string,string> ("b", "c")
    };
    
    vector<double> values {
        2.0, 3.0
    };
    
    vector<pair<string,string>> queries {
        pair<string,string> ("a", "c"),
        pair<string,string> ("b", "a"),
        pair<string,string> ("a", "e"),
        pair<string,string> ("a", "a"),
        pair<string,string> ("x", "x")
    };
    
    vector<double> r = sol.calcEquation(equations, values, queries);
    for (double a: r) {
        cout << a << '\n';
    }
    
    return 0;
}
