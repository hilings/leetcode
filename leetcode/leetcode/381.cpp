//
//  381.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/13/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
    unordered_map<int,unordered_set<int>> um;	// num => [indices]
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        cout << "\ninserting " << val << '\n';
        bool r = um.find(val) == um.end();
        if (r) {
            um[val] = unordered_set<int> {};
        }
        um[val].insert((int)nums.size());
        nums.push_back(val);
        return r;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        cout << "\nremoving " << val << '\n';
        if (um.find(val) == um.end()) {
            return false;
        }

        int index = *(um[val].begin());
        um[val].erase(um[val].begin());
        if (um[val].empty()) {
            um.erase(val);
        }

        if (um.find(nums.back()) != um.end()) {	// adjustment needed if val being deleted is not the last one
            um[nums.back()].erase((int)nums.size()-1);
            um[nums.back()].insert(index);
        }
        nums[index] = nums.back();
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        cout << "\ngetting random\n";
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 381. Insert Delete GetRandom O(1) - Duplicates allowed, C++ ...\n\n";

    // Init an empty collection.
    RandomizedCollection collection;// = new RandomizedCollection();

    /*
     // Inserts 1 to the collection. Returns true as the collection did not contain 1.
     bool r = collection.insert(1);
     cout << (r ? "true" : "false") << '\n';

     // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
     r = collection.insert(1);
     cout << (r ? "true" : "false") << '\n';

     // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
     r = collection.insert(2);
     cout << (r ? "true" : "false") << '\n';

     // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
     int i = collection.getRandom();
     cout << i << '\n';

     // Removes 1 from the collection, returns true. Collection now contains [1,2].
     collection.remove(1);
     cout << (r ? "true" : "false") << '\n';

     // getRandom should return 1 and 2 both equally likely.
     i = collection.getRandom();
     cout << i << '\n';
     */

    bool r = collection.insert(0);
    cout << (r ? "true" : "false") << '\n';
    
    r = collection.remove(0);
    cout << (r ? "true" : "false") << '\n';
    
    r = collection.insert(-1);
    cout << (r ? "true" : "false") << '\n';
    
    r = collection.remove(0);
    cout << (r ? "true" : "false") << '\n';
    
    int i = collection.getRandom();
    cout << i << '\n';
    
    
    return 0;
}
