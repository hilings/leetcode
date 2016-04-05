//
//  208.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    bool isLeaf;
    vector<TrieNode*> children;

    TrieNode(char c) : val(c), isLeaf(false), children(vector<TrieNode*> (26, NULL)) {};
    TrieNode() {
        val = ' ';
        isLeaf = false;
        children = vector<TrieNode*> (26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL)
                cur->children[word[i]-'a'] = new TrieNode(word[i]);
            cur = cur->children[word[i]-'a'];
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL)
                return false;
            cur = cur->children[word[i]-'a'];
        }
        return cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (cur->children[prefix[i]-'a'] == NULL)
                return false;
            cur = cur->children[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 208. Implement Trie (Prefix Tree), C++ ...\n\n";
    Trie t;

    bool r = t.search("a");
    cout << (r ? "true" : "false") << '\n';
    
    t.insert("abc");
    
    r = t.search("abc");
    cout << (r ? "true" : "false") << '\n';
    
    r = t.startsWith("ab");
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}