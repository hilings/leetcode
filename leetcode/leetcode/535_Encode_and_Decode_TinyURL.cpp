//
//  535_Encode_and_Decode_TinyURL.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string,string> long_tiny, tiny_long;
    int n = 6;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string randomCode(int length) {
        string r = "";
        for (int i = 0; i < length; i++) {
            r += alphabet[rand() % alphabet.size()];
        }
        return r;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long_tiny.find(longUrl) == long_tiny.end()) {
            string tiny = randomCode(n);
            while (tiny_long.find(tiny) != tiny_long.end()) {
                tiny = randomCode(n);
            }
            tiny_long[tiny] = longUrl;
            long_tiny[longUrl] = tiny;
        }
        return long_tiny[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tiny_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 535. Encode and Decode TinyURL, C++ ...\n\n";
    Solution sol;

    string longUrl = "";
    cout << longUrl << '\n';

    string encoded = sol.encode(longUrl);
    cout << encoded << '\n';

    string decoded = sol.decode(encoded);
    cout << decoded << '\n';

    return 0;
}
