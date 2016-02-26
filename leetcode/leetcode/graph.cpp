//
//  graph.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/20/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    vector<string> explodeNode(string s) {
        vector<string> v;
        for (int i = 0, j = i; i < s.size(); i = (++j)) {
            while (j < s.size() && s[j] != '#')
                j++;
            v.push_back(s.substr(i, j-i));
        }
        return v;
    }
    vector<int> explodeEdge(string s) {
        vector<int> v;
        for (int i = 0, j = i; i < s.size(); i = (++j)) {
            while (j < s.size() && s[j] != ',')
                j++;
            v.push_back(stoi(s.substr(i, j-i)));
        }
        return v;
    }

public:
    UndirectedGraphNode* buildGraph(string s) {
        vector<pair<int,int>> edges;
        unordered_map<int,UndirectedGraphNode*> nodes;

        for (string nodeSerials: explodeNode(s)) {
            vector<int> edgeSerials = explodeEdge(nodeSerials);
            int label = edgeSerials[0];
            nodes[label] = new UndirectedGraphNode(label);
            for (int i = 1; i < edgeSerials.size(); i++) {
                edges.push_back(pair<int,int> (label, edgeSerials[i]));
                //cout << "( " << label << ", " << edgeSerials[i] << ")\n";
            }
        }
        for (pair<int,int> p: edges) {
            nodes[p.first]->neighbors.push_back(nodes[p.second]);
            if (p.first != p.second)
                nodes[p.second]->neighbors.push_back(nodes[p.first]);
        }
        return nodes[edges[0].first];
    }

    void printG(UndirectedGraphNode *node) {
        vector<pair<int,int>> edges;
        unordered_map<int,UndirectedGraphNode*> visited;
        deque<UndirectedGraphNode*> q {node};
        string serial = "";
        while (!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop_front();
            if (visited.find(cur->label) != visited.end())
                continue;
            visited[cur->label] = cur;
            serial += "#" + to_string(cur->label);
            //cout << "visiting " << cur->label << '\n';
            for (UndirectedGraphNode* nb: cur->neighbors) {
                if (visited.find(nb->label) == visited.end() || nb->label == cur->label) {
                    q.push_back(nb);
                    serial += "," + to_string(nb->label);
                }
            }
        }
        cout << serial.substr(1) << '\n';
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 Undirected Graph, C++ ...\n\n";
    Solution sol;

    string s = "0,1,2#1,2#2,2";
    UndirectedGraphNode *r = sol.buildGraph(s);

    /*
    for (UndirectedGraphNode* node: r->neighbors) {
        cout << node->label << ": ";
        for (UndirectedGraphNode* nb: node->neighbors) {
            cout << nb->label << " ";
        }
        cout << '\n';
    }
     */

    sol.printG(r);

    return 0;
}