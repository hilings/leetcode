//
//  380.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/13/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> um;	// num => index
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        cout << "\ninserting " << val << '\n';
        if (um.find(val) != um.end())
            return false;
        um[val] = (int)nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        cout << "\ndeleting " << val << '\n';
        if (um.find(val) == um.end())
            return false;
        nums[um[val]] = nums.back();
        um[nums.back()] = um[val];
        nums.pop_back();
        um.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        cout << "\ngetting random\n";
        return nums[rand() % um.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 380. Insert Delete GetRandom O(1), C++ ...\n\n";

    // Init an empty set.
    RandomizedSet randomSet;// = new RandomizedSet();

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    bool r = randomSet.insert(1);
    cout << (r ? "true" : "false") << '\n';

    // Returns false as 2 does not exist in the set.
    r = randomSet.remove(2);
    cout << (r ? "true" : "false") << '\n';

    // Inserts 2 to the set, returns true. Set now contains [1,2].
    r = randomSet.insert(2);
    cout << (r ? "true" : "false") << '\n';

    // getRandom should return either 1 or 2 randomly.
    int i = randomSet.getRandom();
    cout << i << '\n';

    // Removes 1 from the set, returns true. Set now contains [2].
    r = randomSet.remove(1);
    cout << (r ? "true" : "false") << '\n';

    // 2 was already in the set, so return false.
    r = randomSet.insert(2);
    cout << (r ? "true" : "false") << '\n';
    
    // Since 2 is the only number in the set, getRandom always return 2.
    i = randomSet.getRandom();
    cout << i << '\n';
    
    return 0;
}
