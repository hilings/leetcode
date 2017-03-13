//
//  372.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/29/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
    int superPow0(int a, vector<int>& b) {
        cout << a << " ^ ";
        for (int t: b) {
            cout << t;
        }
        cout << " =\n";

        int d = 1337, exp = 0, rmd = 1, sum = 0 ;
        unordered_map<int,int> map_r_e;		// recurrent remainders to exp
        unordered_map<int,int> map_e_r;		// exp to remainder
        deque<int> q (b.begin(), b.end());

        a %= d;
        while (map_r_e.find(rmd) == map_r_e.end()) {	// break when remainder recurs
            cout << "i = " << exp << ", rmd = " << rmd << "\n";
            map_r_e[rmd] = exp;
            map_e_r[exp++] = rmd;
            rmd = rmd*a % d;
        }
        exp -= map_r_e[rmd];
        cout << "interval = " << exp << '\n';

        while (true) {
            for (int i = min(9, (int)q.size()); i > 0; i--) {
                sum = 10*sum + q.front();
                q.pop_front();
            }
            sum %= exp;
            if (q.empty())
                break;
            while (sum > 0) {
                q.push_front(sum%10);
                sum /= 10;
            }
        }
        cout << a << " ^ " << sum << " = " << map_e_r[sum] << "\n";
        return map_e_r[sum];
    }

    int superPow(int a, vector<int>& b) {
        int d = 1337, bb = 0;
        a %= d;		// let a = kd+r, then a^b % d = (kd+r)^b % d = r^b % d

        vector<int> v;				// repeating remainders
        unordered_set<int> mask;	// whether a remainder repeat
        for (int rmd = a; mask.find(rmd) == mask.end(); rmd = rmd*a % d) {	// find interval of repeating remainders
            v.push_back(rmd);
            mask.insert(rmd);
        }
        cout << "interval = " << v.size() << '\n';

        for (int t: b) {	//	logic of division
            bb = (bb*10 + t) % v.size();
        }
        return bb == 0 ? v.back() : v[bb-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 372. Super Pow, C++ ...\n\n";
    Solution sol;
    
    int a = 7;
    vector<int> b {1,2,3,4,5,6};
    
    int r0 = sol.superPow0(a, b);
    cout << r0 << '\n';
    
    int r = sol.superPow(a, b);
    cout << r << '\n';
    
    return 0;
}
