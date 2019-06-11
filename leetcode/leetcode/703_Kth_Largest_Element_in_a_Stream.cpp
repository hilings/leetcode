//
//  703_Kth_Largest_Element_in_a_Stream.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/11/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class KthLargest {
    int myk;
    multiset<int> os;
public:
    KthLargest(int k, vector<int>& nums) {
        myk = k;
        for (int a: nums) {
            add(a);
        }
    }

    int add(int val) {
        os.insert(val);
        if (os.size() > myk) {
            os.erase(os.begin());
        }
        return *os.begin();
    }



};

class KthLargest2 { // priority_queue
    int myk;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest2(int k, vector<int>& nums) {
        myk = k;
        for (int a: nums) {
            add(a);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > myk) {
            pq.pop();
        }
        return pq.top();
    }
};

        
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 703. Kth Largest Element in a Stream, C++ ...\n\n";

    int k = 3;
    vector<int> arr {4,5,8,2};
    KthLargest2 kthLargest(k, arr);

    int r = kthLargest.add(3);   // returns 4
    cout << r << '\n';
    r = kthLargest.add(5);   // returns 5
    cout << r << '\n';
    r = kthLargest.add(10);  // returns 5
    cout << r << '\n';
    r = kthLargest.add(9);   // returns 8
    cout << r << '\n';
    r = kthLargest.add(4);   // returns 8
    cout << r << '\n';
    // 4,5,5,8,8




    return 0;
}
