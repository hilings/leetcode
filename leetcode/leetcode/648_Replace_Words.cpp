//
//  648_Replace_Words.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/25/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TrieNode {
    char c;
    vector<TrieNode*> children;
    bool isWord;
    TrieNode(char x) : c(x), children(vector<TrieNode*> (26, NULL)), isWord(false) {}
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> dict2;
        for (string& d: dict) {
            dict2.insert(d);
        }
        string r = "";
        unordered_map<string,string> um;
        for (string::size_type i = 0, n = sentence.size(), pos; i < sentence.size(); i = pos+1) {
            pos = sentence.find(' ', i);
            if (pos == string::npos) {
                pos = n;
            }
            string word = sentence.substr(i, pos-i);

            if (um.find(word) == um.end()) {    // new word
                for (int j = 1; j <= word.size(); j++) {
                    string root = word.substr(0, j);
                    if (dict2.find(root) != dict2.end()) {
                        um[word] = root;    // found a root
                        break;
                    }
                }
                if (um.find(word) == um.end()) {    // this word has no root
                    um[word] = word;
                }
            }
            r += r == "" ? um[word] : " " + um[word];
        }
        return r;
    }

    string replaceWords2(vector<string>& dict, string sentence) {
        // build a Trie
        TrieNode* trie = new TrieNode(' ');
        for (string s: dict) {
            TrieNode* cur = trie;
            for (char c: s) {
                int i = c-'a';
                if (!cur->children[i]) {
                    cur->children[i] = new TrieNode(c);
                }
                cur = cur->children[i];
            }
            cur->isWord = true;
        }
        string r = "";
        // parse each word
        for (string::size_type i = 0, pos; i < sentence.size(); i = pos+1) {
            pos = sentence.find(' ', i);
            if (pos == string::npos) {
                pos = sentence.size();
            }
            TrieNode* cur = trie;
            string word = sentence.substr(i, pos-i);
            string root = word;
            for (int i = 0; i < word.size() && cur->children[word[i]-'a']; i++) {
                if (cur->children[word[i]-'a']->isWord) {
                    root = word.substr(0, i+1);
                    break;
                }
                cur = cur->children[word[i]-'a'];
            }
            r += root + ' ';
        }
        r.pop_back();   // erase last space
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 648. Replace Words, C++ ...\n\n";
    Solution sol;

    vector<string> dict {
        "cat", "bat", "rat"
    };
    string sentence = "the cattle was rattled by the battery";  // the cat was rat by the bat

    string r = sol.replaceWords(dict, sentence);
    cout << r << '\n';

    string r2 = sol.replaceWords2(dict, sentence);
    cout << r2 << '\n';

    return 0;
}
