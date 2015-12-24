//
//  068.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/21/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << '"' << v[i] << "\"\n";
    }
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;
        size_t length = 0;
        vector<string> line;
        for (size_t i = 0; i < words.size(); i++) {
            if (words[i].size() > maxWidth) {
                v.push_back(joinLine(line, maxWidth));
                return v;
            } else if (length == 0) {
                line.push_back(words[i]);
                length += words[i].size();
            } else if (length + words[i].size() + 1 <= maxWidth) {
                line.push_back(words[i]);
                length += words[i].size()+1;
            } else {
                v.push_back(joinLine(line, maxWidth));
                line.clear();
                length = 0;
                i--;
            }
        }
        v.push_back(joinLine(line, maxWidth, true));
        return v;
    }
    string joinLine(vector<string> line, int maxWidth, bool last = false) {
        string s = "";
        if (line.size() == 1 || last) {
            for (size_t i = 0; i < line.size()-1; i++) {
                s.append(line[i] + " ");
                maxWidth -= line[i].size()+1;
            }
            s.append(line.back()+string(maxWidth-line.back().size(), ' '));
            return s;
        }
        for (int i = 0; i < line.size(); i++)
            maxWidth -= line[i].size();
        size_t space = maxWidth / (line.size()-1);
        size_t extra = maxWidth % (line.size()-1);

        for (size_t i = 0; i < extra; i++)
            s.append(line[i] + string(space+1, ' '));
        for (size_t i = extra; i < line.size()-1; i++)
            s.append(line[i] + string(space, ' '));
        s.append(line.back());
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 068 Text Justification, C++ ...\n\n";
    Solution sol;
    
    vector<string> words = {
        ///*
        "This", "is", "an",
        "example", "of", "text",
        "justification."
        //*/
        //""
        /*
         "What", "must", "be",
         "shall", "be."
         */
    };
    int maxWidth = 14;
    
    vector<string> r = sol.fullJustify(words, maxWidth);
    printV(r);
    
    return 0;
}