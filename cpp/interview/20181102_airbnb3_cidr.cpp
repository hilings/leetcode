//
//  20181102_airbnb3_cidr.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> cidr(string ip, int n) {
        vector<string> r;
        unsigned int iip = ipToInt(ip);
        cout << iip << '\n';

        string ip2 = intToIP(iip);
        cout << ip2 << '\n';

        helper(iip, n, r);
        return r;
    }

    void helper(unsigned int ip, int n, vector<string>& r) {
        if (n == 0) {
            return ;
        }
        int i;
        for (i = 0; i <= 31 && ((1<<i) & ip) == 0 && n >= (1<<(i+1)); i++) {    }
        r.push_back(intToIP(ip & (-1 << i)) + "/" + to_string(32-i));
        helper(ip + (1<<i), n - (1<<i), r);
    }

    string intToIP(unsigned int n) {
        string r = "";
        for (int i = 0; i < 4; i++) {
            r = to_string(n & 255) + "." + r;
            n >>= 8;
        }
        r.pop_back();
        return r;
    }

    unsigned int ipToInt(string ip) {
        unsigned int r = 0;
        for (string::size_type i = 0, pos = 0; i < ip.size(); i = pos+1) {
            pos = ip.find('.', i);
            if (pos == string::npos) {
                pos = ip.size();
            }
            r = (r << 8) + stoi(ip.substr(i, pos-i));
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    string ip = "128.0.0.7";
    ip = "30.12.10.10";
    ip = "0.0.0.0";
    ip = "0.0.0.0";
    ip = "0.0.0.1";

    int n = 4;
    n = 7;
    n = 255;
    n = 8388608;
    n = 257;

    vector<string> r = sol.cidr(ip, n);
    for (string s: r) {
        cout << s << '\n';
    }

    return 0;
}

/*

 iprange_to_cidr("30.12.10.10", 7)

 iprange_to_cidr("0.0.0.0", 255)

 iprange_to_cidr("0.0.0.0", 256)

 iprange_to_cidr("0.0.0.0", 8388608)

 iprange_to_cidr("0.0.0.1", 257)

 */
//'255.12.0.0', 13

/*
 Your previous Plain Text content is preserved below:

 This is just a simple shared plaintext pad, with no execution capabilities.

 When you know what language you'd like to use for your interview,
 simply choose it from the dropdown in the top bar.

 You can also change the default language your pads are created with
 in your account settings: https://coderpad.io/settings

 Enjoy your interview!

 Cidr问题

 问题

 ip 是由32bit构成，比如1000...0101代表的是128.0.0.5，不过当我们要表示一串ip地址的时候一一罗列ip地址是很费力的工作，所以有了cidr表示法，比如我们要表示1000...01??这四个连续的ip地址（128.0.0.4-128.0.0.7）那么它的cidr表示法就是128.0.0.4/30，我们要注意的是并不是所有的cidr表示法都是有效的，比如128.0.0.6/30就是无效的

 以最后8位bit为例
 0 0 0 0 0 1 0 0  ：4
 0 0 0 0 0 1 0 1  ：5
 0 0 0 0 0 1 1 0  ：6
 0 0 0 0 0 1 1 1  ：7
 显然128.0.0.4/30是合法的。

 要求

 给定一连串连续ip地址，将其表示成cidr的集合使其刚好能够覆盖这些连续的ip地址

 样例输入

 iprange_to_cidr("128.0.0.4", 4)

 样例输出

 ["128.0.0.4/30"] # Like in the description above



 "128.0.0.5", 4
 0101 128.0.0.5/32
 0110 128.0.0.6/31
 0111
 1000 128.0.0.8/32

 "128.0.0.7", 4
 0111  7/32
 1000  8/31
 1001
 1010  10/32
 */
