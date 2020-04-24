//
//  135.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/24/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies (ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            } else if (ratings[i] < ratings[i-1]) {
                int j = i;
                while (j+1 < ratings.size() && ratings[j+1] < ratings[j])
                    j++;
                for (int k = j-1; k >= i; k--)
                    candies[k] = candies[k+1]+1;
                candies[i-1] = max(candies[i-1], candies[i]+1);
                i = j;
            }
        }
        for (int a: candies) {
            cout << a << " ";
        }
        cout << '\n';

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 135. Candy, C++ ...\n\n";
    Solution sol;
    
    vector<int> ratings {1,2,3,3,2,1};
    
    int r = sol.candy(ratings);
    cout << r << '\n';
    
    return 0;
}