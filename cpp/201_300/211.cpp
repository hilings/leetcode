//
//  211.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/11/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    char val;
    bool isWord;
    vector<TrieNode*> children;
    TrieNode(char c) : val(c), isWord(false), children(vector<TrieNode*> (26, NULL) ) {}
};

class WordDictionary {
    TrieNode *root;
    bool solve(string& word, int pos, TrieNode* cur) {
        if (pos == word.size())
            return cur->isWord;
        if (word[pos] != '.')
            return cur->children[word[pos]-'a'] == NULL ? false : solve(word, pos+1, cur->children[word[pos]-'a']);
        for (int i = 0; i < 26; i++) {
            if (cur->children[i] && solve(word, pos+1, cur->children[i]))
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode(' ');
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        //cout << "inserting " << word << '\n';
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL)
                cur->children[word[i]-'a'] = new TrieNode(word[i]);
            cur = cur->children[word[i]-'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        //cout << "searching " << word << '\n';
        return solve(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 211. Add and Search Word - Data structure design, C++ ...\n\n";
    WordDictionary wordDictionary;
    
    wordDictionary.addWord("word");
    wordDictionary.addWord("ward");
    
    bool r = wordDictionary.search("word");
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}