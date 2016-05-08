//
//  212.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/11/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    string word;
    vector<TrieNode*> children;
    TrieNode() : word(""), children(vector<TrieNode*> (26, NULL) ) {}
};

class Solution {
    void insertWord(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            //cout << word[i] << '\n';
            if (cur->children[c-'a'] == NULL)
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->word = word;
    }
public:
    TrieNode *root;
    Solution() {
        root = new TrieNode();
    }
    ~Solution() {
        delete root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string w: words) {
            insertWord(w);
        }
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                //cout << "[" << i << ", " << j << "] = " << board[i][j] << "\n";
                solve(board, root, i, j, res);
            }
        }
        return res;
    }
    void solve(vector<vector<char>>& board, TrieNode* cur, int i, int j, vector<string>& res) {
        char c = board[i][j];
        if (c == '*' || cur->children[c-'a'] == NULL)
            return;
        cur = cur->children[c-'a'];
        if (!cur->word.empty()) {
            res.push_back(cur->word);
            cur->word = "";		// remove duplicated
        }
        board[i][j] = '*';
        if (i-1 >= 0)
            solve(board, cur, i-1, j, res);
        if (i+1 < board.size())
            solve(board, cur, i+1, j, res);
        if (j-1 >= 0)
            solve(board, cur, i, j-1, res);
        if (j+1 < board[0].size())
            solve(board, cur, i, j+1, res);
        board[i][j] = c;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 212. Word Search II, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> board {
        vector<char> {'o','a','a','n'},
        vector<char> {'e','t','a','e'},
        vector<char> {'i','h','k','r'},
        vector<char> {'i','f','l','v'}
    };
    vector<string> words {"oath", "pea", "eat", "rain"};
    
    vector<string> r = sol.findWords(board, words);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}