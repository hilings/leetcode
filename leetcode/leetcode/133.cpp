//
//  133.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/19/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
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
        UndirectedGraphNode* ret = NULL;
        for (string nodeSerials: explodeNode(s)) {
            vector<int> edgeSerials = explodeEdge(nodeSerials);
            int label = edgeSerials[0];
            nodes[label] = new UndirectedGraphNode(label);
            if (ret == NULL)
                ret = nodes[label];
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
        return ret;
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

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        deque<UndirectedGraphNode*> q {node};
        unordered_map<int,UndirectedGraphNode*> nodes;
        vector<pair<int,int>> edges;
        UndirectedGraphNode* ret = NULL;
        while (!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop_front();
            if (nodes.find(cur->label) != nodes.end())
                continue;
            nodes[cur->label] = new UndirectedGraphNode(cur->label);
            if (ret == NULL)
                ret = nodes[cur->label];
            for (UndirectedGraphNode* nb: cur->neighbors) {
                q.push_back(nb);
                edges.push_back(pair<int,int> (cur->label,nb->label));
            }
        }
        for (pair<int,int> p: edges) {
            //cout << "( " << p.first << ", " << p.second << ")\n";
            nodes[p.first]->neighbors.push_back(nodes[p.second]);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 133 Clone Graph, C++ ...\n\n";
    Solution sol;

    string s = "0,1,2#1,2#2,2";
    s = "-1";

    UndirectedGraphNode *graph = sol.buildGraph(s);
    sol.printG(graph);

    UndirectedGraphNode* r = sol.cloneGraph(graph);
    sol.printG(r);
    
    return 0;
}