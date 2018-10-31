//
//  676_Implement_Magic_Dictionary.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/30/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class MagicDictionary {
    unordered_set<string> us;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string s: dict) {
            us.insert(s);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == word[i]) {
                    continue;
                }
                string s = word.substr(0, i) + c + word.substr(i+1);
                if (us.find(s) != us.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 676. Implement Magic Dictionary, C++ ...\n\n";
    MagicDictionary md;

    vector<string> dict {
        "hello", "leetcode"
    };
    md.buildDict(dict);

    string word = "hello";
    bool r = md.search(word);
    cout << (r ? "true" : "false") << '\n';

    word = "hhllo";
    r = md.search(word);
    cout << (r ? "true" : "false") << '\n';

    word = "hell";
    r = md.search(word);
    cout << (r ? "true" : "false") << '\n';

    word = "leetcoded";
    r = md.search(word);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
