//
//  327.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct MyTreeNode {
    int val, count;
    MyTreeNode *left, *right;
    MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countRangeSum0(vector<int>& nums, int lower, int upper) {	// brute force
        vector<long> S {0};
        for (int i = 0; i < nums.size(); i++) {
            S.push_back(S[i]+nums[i]);
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                long int rangeSum = S[j+1]-S[i];
                if (rangeSum >= lower && rangeSum <= upper)
                    count++;
            }
        }
        return count;
    }

    /////////////////////////////////////////////////////
    int countRangeSum1(vector<int>& nums, int lower, int upper) {	// Binary Search with vector
        int count = 0;
        long int sum = 0;
        vector<long int> sums {0};
        for (int a: nums) {
            sum += a;
            count += upper_bound(sums.begin(), sums.end(), sum-lower) - lower_bound(sums.begin(), sums.end(), sum-upper);
            sums.insert(lower_bound(sums.begin(), sums.end(), sum), sum);
        }
        return count;
    }

    int countRangeSum2(vector<int>& nums, int lower, int upper) {	// Binary Search with multiset
        int count = 0;
        long int sum = 0;
        multiset<long int> sums {0};
        for (int a: nums) {
            sum += a;
            count += distance(sums.lower_bound(sum-upper), sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return count;
    }

    /////////////////////////////////////////////////////
    int countRangeSum3(vector<int>& nums, int lower, int upper) {	// Binary Search Tree
        int count = 0;
        long int sum = 0;
        MyTreeNode *root = new MyTreeNode(0);
        for (int a: nums) {
            sum += a;
            count += countNode(root, sum-lower) - countNode(root, sum-upper-1);
            insertNode(root, sum);
        }
        return count;
    }
    int countNode(MyTreeNode *root, long int x) {
        int count = 0;
        while (root) {
            if (x >= root->val) {
                count += root->count;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return count;
    }
    void insertNode(MyTreeNode *root, int x) {
        while (true) {
            if (x <= root->val) {
                root->count++;
                if (root->left) {
                    root = root->left;
                } else {
                    root->left = new MyTreeNode(x);
                    break;
                }
            } else {
                if (root->right) {
                    root = root->right;
                } else {
                    root->right = new MyTreeNode(x);
                    break;
                }
            }
        }
    }

    /////////////////////////////////////////////////////
    int countRangeSum4(vector<int>& nums, int lower, int upper) {	// MergeSort
        int n = (int)nums.size();
        vector<long int> S {0};
        for (int a: nums) {
            S.push_back(S.back() + a);
        }
        return myMergeSort(S, 0, n, lower, upper);
    }
    int myMergeSort(vector<long int>& S, int begin, int end, int lower, int upper) {
        if (begin >= end)
            return 0;
        int mid = begin + (end-begin)/2, count = myMergeSort(S, begin, mid, lower, upper) + myMergeSort(S, mid+1, end, lower, upper);
        vector<long int> v;
        for (int i = begin, j = mid+1; i <= mid; i++) {
            count += upper_bound(S.begin()+mid+1, S.begin()+end+1, S[i]+upper) - lower_bound(S.begin()+mid+1, S.begin()+end+1, S[i]+lower);
            while (j <= end && S[i] > S[j])
                v.push_back(S[j++]);
            v.push_back(S[i]);
        }
        move(v.begin(), v.end(), S.begin()+begin);
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 327. Count of Range Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nums {-2, 5, -1};
    int lower = -2, upper = 2;

    //vector<int> nums {-2147483647,0,-2147483647,2147483647};
    //int lower = -564, upper = 3864;

    //vector<int> nums {2147483647,-2147483648, -1, 0};
    //int lower = -1, upper = 0;

    //vector<int> nums {-6,20,-7,1,22,6,7,-2,12,19,-14,-19,-11,22,-8,-7,10,-27,-23,-7,17,18,-16,-11,18,-29,-14,9,19,-2,17,13,27,12,4,-23,0,5,24,11,7,23,-18,2,1,28,8,13,25,4,-21,-11,-7,0,11,-4,24,6,-10,-23,-19,5,-9,-6,-23,7,-22,24,-13,2,-26,-7,-19,25,-9,2,-5,18,22,12,-16,-27,-1,7,29,14,-7,-1,-22,12,-10,27,-20,-6,-15,-1,-3,-16,5,-19,11,-29,-12,-12,-8,-19,2,-22,-4,19,-19,-19,17,5,17,5,27,6,9,-4,28,-30,12,26,7,5,27,24,13,-28,4,29,-11,22,4,-11,-3,9,2,18,-25,-15,14,11,26,7,-30,16,10,-21,20,5,1,-25,6,-28,-13,-30,-8,21,-13,-19,15,12,13,-15,0,26,5,-16,-29,5,-16,10,1,17,-3,16,5,-29,16,4,-22,28,-25,-29,-17,-6,-13,-12,26,-9,-27,-9,-5,-15,18,2,29,25,18,-1,-3,-4,17,-17,-6,-12,8,19,-18,11,21,18,-9,-1,-7,23,24,-1,8,-11,3,21,-7,-8,-1,-3,21,-6,26,-15,9,-4,-4,-25,-29,-4,1,-15,29,13,13,8,-18,13,7,-27,7,2,27,5,-18,11,24,-29,-27,3,23,12,-3,14,-15,22,-29,-5,1,-14,13,-19,-7,8,22,25,-17,14,15,-2,25,-26,-11,21,6,-8,-24,24,-28,17,19,17,-17,-23,-5,20,-28,0,-30,-14,7,-4,12,2,3,6,-3,-17,-13,28,27,11,-18,-18,-29,23,17,-2,14,10,-7,15,14,-20,0,-11,6,25,-8,20,-16,-20,27,-23,7,-29,27,-30,24,-20,-2,-26,18,21,26,-18,13,-8,-2,13,-23,3,25,29,29,-8,9,-1,-1,-7,-23,24,0,-2,-13,-1,7,-20,4,20,18,11,22,-18,29,19,-15,9,15,13,-5,13,25,-27,9,-20,-26,-21,22,16,17,-1,2,-6,21,10,5,-8,3,-4,-20,-4,14,24,-27,14,8,-1,-2,-2,25,-3,-21,12,-27,-23,-7,11,24,-28,-20,-28,21,9,21,-15,29,12,9,-20,9,-27,1,6,10,-12,-6,18,-26,-16,-13,7,4,-19,-29,16,-10,7,8,-15,-22,-12,-7,-25,-29,-6,12,-27,14,-5,1,-7,13,25,-24,11,-7,23,14,-12,28,-3,-18,-5,-22,-12,25,-15,-9,-21,-24,-4,10,-7,20,4,6,5,20,-30,6,23,-1,1,-16,14,9,1,-5,7,4,-22,25,-8,-1,-5,20,10,-17,5,-23,1,3,-28,-1,-25,6,-8,-14,-28,21,12,-24,-27,-14,12,-2,-10,3,14,-20,22,-12,24,-2,-29,-12,5,10,-8,-28,-18,23,-8,6,7,17,1,-3,-26,4,-19,6,4,-25,4,-21,-1,-18,10,-12,13,-25,12,-2,20,-18,23,-1,-13,-8,18,21,-28,6,-30,-7,-18,4,11,-20,-13,0,-27,16,-20,-15,28,24,-22,-24,-10,-10,-14,-26,24,-30,-4,18,-11,18,23,-29,-22,17,24,1,13,-1,18,-16,6,-17,7,-19,24,-17,18,-7,22,-1,13,-3,-6,26,17,0,-6,29,-8,-15,-1,6,27,21,18,8,22,9,-9,-27,10,17,-15,-2,18,3,-6,19,-7,27,18,-5,11,17,10,-29,26,-7,-9,19,6,-12,-14,-2,22,-1,26,-18,18,-23,10,3,-14,-25,0,18,-1,28,-1,-8,-27,-29,-10,29,-3,7,6,3,-22,25,10,22,4,18,2,-15,4,-18,-3,12,-21,6,7,17,-26,-2,12,14,-13,29,-29,13,22,-19,-28,0,-17,-28,-10,-24,16,20,8,-12,22,8,6,14,-22,-16,19,17,-18,12,11,-17,-30,22,-24,-29,21,12,-6,-5,-27,-15,12,-28,28,3,5,11,12,-22,0,-4,1,10,0,2,6,-29,-11,-15,-5,22,28,-28,-2,-25,-23,-5,-22,-27,23,-18,0,19,-3,-15,17,-11,-7,24,9,15,2,-22,9,-25,-13,-3,10,13,-10,-16,9,-20,7,-23,7,9,14,-8,18,-1,20,18,-19,3,-17,-8,1,9,-16,-30,18,12,-21,-13,6,-1,18,-25,25,20,11,15,-19,-1,-20,-2,28,-28,-4,1,4,-29,24,19,-17,9,15,0,13,24,23,23,4,27,-14,25,23,-9,11,23,-17,14,-29,-3,26,-1,14,19,9,-8,-14,23,-15,-23,-30,28,-14,-19,0,25,13,-3,7,-23,8,-11,16,19,13,3,-16,10,4,1,-10,11,-7,11,3,-8,-30,-27,28,21,9,27,-1,14,-26,23,-21,11,29,9,2,25,27,10,-12,22,0,22,2,16,-28,23,-3,-21,18,28,-18,4,-13,8,-13,3,19,28,7,9,-8,-9,-25,-5,16,-1,-15,-2,-4,-10,6,16,-5,-3,1,-15,19,6,-5,-17,25,-7,-30,24,0,-1,10,1,-28,10,-22,9,-18,-19,0,4,11,20,16,-14,-5,-18,-29,4,11,7,-15,4,-10,9,-16,-26,-27,10,12,0,-6,-5,-11,24,-4,13,28,-23,26,21,-29,-10,-3,20,-9,15,24,-8,11,-30,-1,17,18,-25,-16,11,21,-7,19,5,-7,4,3,1,-15,27,2,-14,-3,-18,-6,-9,-5,14,-21,2,5,18,3,-27,28,10,0,2,-4,-8,-3,22,2,22,-14,3,-17,11,9,7,-2,-14,-17,-3,13,4,-20,-12,8,-21,-15,-30,8,27,-12,-2,-24,-15,-6,-25,19,20,5,9,18,-17,-9,-29,27,-2,-13,-26,2,-27,-1,1,0,-13,-4,10,15,-27,-21,25,-21,-15,8,13,-13,-10,5,19,-5,-22,-16,20,29,-20,26,-13,1,-3,9,19,4,5,-15,-22,2,19,-16,-14,-28,4,-16,-25,9,-26,-22,8,-4,-30,-8,-13,15,20,-22,-10,-25,19,-22,-17,-27,4,-16,4,-7,9,-26,29,10,-17,13,-4,6,9,28,19,-24,-12,-15,-7,-25,-13,15,2,-3,-24,-20,17,5,22,-4,-12,23,-6,-10,19,-17,13,18,-14,18,20,-28,-11,9,-25,-27,-10,22,8,-25,13,-15,-9,4,5,-17,15,20,-28,3,24,20,-3,27,13,9,-22,-2,-30,-8,24,20,-18,-4,-21,-3,-2,-15,-21,-16,6,-8,-27,1,2,1,0,-30,-15,20,19,12,-6,21,-25,28,11,-29,3,4,15,25,-24,5,21,13,-28,28,3,-23,19,26,21,-10,-16,-1,10,15,-6,15,2,27,-18,8,-2,1,14,16,21,6,4,-28,12,-19,-23,-3,-28,19,10,-25,1,12,-23,24,2,-14,-19,4,1,9,19,-8,9,-3,-3,-13,10,1,13,-15,7,-19,-5,3,-27,3,28,-28,16,-6,23,-8,-20,23,14,-14,-26,-15,26,23,-26,16,-4,10,-9,27,12,6,-18,-16,20,29,12,-24,-14,27,-29,20,-20,-18,-19,18,-23,22,-4,-26,17,24,10,-10,-3,25,-11,12,-23,25,20,23,11,5,-24,-28,16,-6,5,-4,-17,8,-19,7,-6,11,19,28,22,-18,2,12,-29,26,-7,-19,28,17,23,-12,-3,-24,16,-25,2,-17,18,1,-23,21,-22,-1,17,-28,-5,26,-3,-5,22,11,-8,19,-27,14,11,-25,-27,6,14,20,7,13,-16,13,-10,-22,21,-12,-25,21,-6,-2,-5,-13,28,-30,-6,-10,18,14,-11,14,5,25,13,0,18,-19,28,13,-13,17,25,15,28,-21,-1,-1,-24,-3,-4,-2,4,-23,-4,11,-9,15,-3,-6,-27,-9,-11,11,12,-15,-13,-3,19,-6,-20,3,26,-28,-2,9,18,-11,11,9,-1,1,-1,-16,-6,10,-16,7,4,-23,20,8,-27,-20,-2,2,4,-6,-10,14,-25,-12,-23,22,17,-22,-8,8,17,-23,-18,-11,-21,-8,2,8,13,9,-8,-25,-10,0,-17,-19,-22,7,12,-7,3,-15,10,2,6,21,17,28,19,-2,9,12,-10,-27,12,-4,6,-29,0,14,16,18,16,-13,25,-13,-17,-16,-11,-2,22,-11,-16,-19,-1,-13,27,-26,10,-24,0,25,5,12,28,-17,-12,-1,9,1,22,14,16,16,-28,-12,-19,6,-17,23,-2,7,-14,-21,-26,-5,-30,3,15,27,-23,-18,12,-26,14,9,-24,-15,-9,16,-28,7,19,-25,12,5,-9,-24,14,-14,7,3,-12,11,-18,22,-13,9,-26,18,-3,-20,-30,14,-1,-19,-22,-17,1,-16,-15,-7,-28,-12,3,2,-15,-21,-1,-7,0,-10,-8,19,3,22,15,-18,18,26,19,6,-19,29,-27,0,-27,-25,12,-27,1,-12,-18,-11,-25,9,6,3,26,-8,-14,10,-29,-2,-16,29,5,-12,-28,-13,-17,4,-7,4,8,6,13,-19,6,11,-27,24,-20,-15,22,1,-26,29,-11,25,-4,-18,28,3,-13,-1,-14,26,-9,-19,-25,21,-2,-29,-11,-29,-26,-26,-13,-8,-10,-19,-1,-28,3,10,24,-17,18,-16,-25,-23,-29,10,-9,29,-4,4,-13,25,27,24,10,12,-29,-17,26,1,-6,27,3,8,-19,6,-20,4,29,1,1,16,25,-25,20,-10,-30,4,5,-22,6,-26,-3,-5,29,-5,-14,25,-22,-3,9,-13,1,-8,-3,-17,-1,-30,8,25,-13,25,-7,-15,-15,-7,16,-18,-19,-16,-28,-8,1,16,-21,16,-8,5,3,23,7,4,-8,-7,-26,28,-7,17,24,20,-11,-25,29,-15,-1,5,-16,22,0,6,17,18,-30,-7,-3,-25,9,-9,-23,13,12,10,-10,-3,-19,2,22,-20,-6,-28,28,12,1,-19,-14,11,21,16,4,23,7,-23,10,18,3,19,-30,18,-21,17,24,1,14,-18,-5,-29,7,19,8,9,1,-19,19,-29,15,-20,-5,-19,5,-22,-25,12,-18,29,-17,-29,17,13,4,9,10,-10,-5,27,13,-29,18,23,-9,-25,29,-15,10,13,-18,0,-12,-29,-29,4,-24,-25,15,23,27,-9,12,23,10,11,-8,21,-15,-27,-15,-8,-19,21,15,-24,-5,-9,-11,-15,1,-1,27,23,-2,7,26,-8,-26,16,19,7,28,26,-21,-24,23,-18,24,29,-4,-13,-20,20,-2,-15,-10,2,1,-29,-17,-23,1,19,-17,1,23,-12,18,-14,-14,-25,-30,13,16,28,-7,12,-24,28,-19,-15,8,-4,12,11,-21,21,-25,-22,-11,-9,-9,-19,8,-23,14,9,-13,2,0,-13,10,-18,-2,11,-20,14,-7,29,1,-29,27,2,4,23,18,17,-6,-25,3,23,-11,-6,26,-24,0,-27,9,-16,-8,-8,27,14,-28,-8,-22,9,10,23,16,28,17,18,15,-12,-16,29,2,18,25,-26,12,-6,-25,-12,24,4,-3,23,-18,-15,-16,15,-20,22,-7,21,1,-27,-20,1,9,-2,-7,21,11,22,21,-2,-29,2,4,-18,-1,-26,-18,15,24,-4,21,-4,-5,-4,-6,10,-30,-29,16,5,17,14,-26,29,-23,1,-27,-4,9,28,29,21,1,-20,-23,-24,8,11,-1,13,-10,-13,-10,-25,-14,-14,19,-2,19,-4,11,-8,13,-19,-10,-22,-21,-10,-3,23,-25,-22,-18,-9,14,2,-22,2,28,-26,1,-13,27,6,10,15,16,18,25,7,15,-21,-4,19,5,28,-14,21,25,8,21,-26,15,29,-12,-16,27,2,-16,-18,-7,-22,-24,-12,-29,6,-5,22,-22,-27,-6,-11,-29,26,-20,21,13,-17,1,-14,15,-7,-20,-14,27,21,5,-25,-14,6,23,26,16,-28,-24,29,25,17,-7,-24,-14,6,9,3,-2,-13,3,-23,17,-12,-12,-12,2,-20,-13,2,1,-16,-13,21,15,24,-9,24,-14,15,-15,14,-6,0,-2,23,-2,10,-13,13,-11,-20,-20,21,-7,-6,-11,0,5,0,-2,-6,-9,17,-11,-18,-27,1,-12,-25,9,-9,20,-18,17,-5,20,-20,-23,-4,-17,-15,-24,14,17,29,17,10,10,-22,9,15,13,-10,27,-15,28,-19,1,5,-3,16,-29,17,20,-14,-29,6,-4,16,-10,-4,-19,-11,14,-3,12,27,-15,10,7,-15,10,-17,27,26,-29,-10,-6,-29,-22,-4,-5,13,22,-8,-6,-26,-17,25,-18,-30,23,-5,-3,22,-5,-15,6,8,-19,22,6,-6,-5,29,-23,-2,-27,-20,-23,19,17,-30,-14,-4,8,29,0,21,2,28,-26,-22,-9,24,4,15,4,-26,19,-15,1,25,9,-11,-27,26,-17,-17,-28,18,5,-17,10,-21,-23,23,3,3,8,-28,23,18,-9,28,-11,15,-15,5,29,-17,-30,-19,5,-9,23,9,-21,-12,-3,-24,28,-24,4,0,27,2,-26,-4,-15,14,26,15,15,-27,-26,24,-9,-11,0,-12,29,14,-20,16,17,-8,13,27,-15,4,-13,24,8,-10,4,-3,-5,9,3,-2,9,7,4,1,-30,7,-29,-21,-16,-30,9,11,9,10,-3,2,-11,-14,-7,15,-7,18,4,1,-18,25,16,-4,8,-10,-3,5,-18,10,4,-1,-13,18,10,15,4,16,9,11,-16,-2,-23,11,1,26,-15,-12,-4,-15,-3,-25,-7,5,13,14,-10,-5,7,-30,18,5,29,17,10,4,-26,-18,-30,-2,23,28,-1,-1,-8,-29,10,-2,16,15,-3,-5,-2,-20,5,25,-19,6,-10,14,-17,7,28,-14,8,-22,-12,-26,-23,3,-12,-3,19,1,-3,22,-23,-17,-2,-15,-25,4,25,-17,3,21,-6,1,6,-30,-8,20,-17,-30,-24,9,-5,-9,-19,-12,-7,-22,29,-25,-22,19,7,17,9,-2,10,24,9,-30,15,28,-25,27,20,6,23,19,-25,18,-4,-19,5,-19,0,-12,12,6,27,-25,-11,-29,-1,-22,4,25,8,16,-6,14,-22,26,-27,16,-8,17,15,-9,21,16,-16,14,-14,14,9,-6,-30,-12,-26,-12,-2,22,-24,6,-30,21,-3,-18,6,17,-25,12,-30,-20,-13,-27,-24,3,3,-4,-21,-17,-22,-7,-27,21,-5,5,18,-28,10,22,-16,28,-10,-25,12,21,-30,8,-2,-15,-5,20,-6,19,-26,-28,-4,1,16,-2,21,-27,9,-22,-28,-16,19,21,-29,19,4,-25,-29,-16,-17,-13,-21,17,-18,-17,26,4,4,-11,17,-4,25,9,-9,-21,18,-12,7,-3,7,-9,12,-4,25,-18,5,-9,-2,17,12,9,-21,9,-7,3,-19,-2,-28,23,4,20,3,18,25,17,-25,9,9,-21,14,20,13,7,29,-30,-27,-15,12,-19,17,-13,3,21,-6,9,26,-27,0,7,-11,-4,24,0,0,14,18,-27,-14,-8,-7,-26,-19,10,14,-3,-25,-12,11,18,21,-16,24,-16,-25,12,28,16,-24,-5,19,28,-28,-3,-11,-30,-19,-24,19,16,21,-1,-30,14,8,-14,-17,19,29,-12,-29,-1,15,-22,8,-23,6,0,-10,-11,-7,-22,-23,-1,23,13,1,28,25,-8,25,29,-17,-6,-24,14,27,-15,19,19,-27,29,-15,-9,-10,-4,-24,-6,-2,-22,6,-15,0,-30,14,-10,20,-8,-18,-23,-23,13,-5,0,-2,13,7,-6,23,-1,-16,-5,5,-8,29,19,22,-7,26,-16,8,27,9,-21,-7,-17,7,-26,4,-22,3,-18,-21,16,13,16,-24,-28,-16,-1,-5,8,-30,9,22,-17,-29,1,-20,7,26,-23,0,-30,-17,28,-15,-28,0,0,-29,-20,-29,6,17,-8,-16,-9,-14,-9,13,-28,8,-17,-30,-18,15,-17,19,-28,19,23,17,-26,29,19,-3,22,-29,-18,12,22,-4,20,-8,-6,-10,26,12,15,24,3,19,-23,8,-8,-21,18,-18,25,-14,13,7,24,2,-10,-20,22,-3,-24,-1,8,24,9,29,4,13,17,19,-26,28,-30,-10,-10,22,-29,-19,9,22,-7,-19,4,-18,-1,5,12,-22,-25,29,23,-16,11,14,27,-1,9,-28,7,-3,-17,-26,28,-23,14,19,-26,-1,-14,-22,-4,-5,-5,25,-12,12,11,4,20,13,24,-16,-30,-5,25,-13,-9,-10,21,-18,29,22,21,17,27,-2,24,-28,-2,-24,-7,0,17,-15,-5,26,25,16,-16,16,27,-14,-24,29,-12,-24,22,10,24,0,7,26,-2,-25,6,12,-24,20,-12,-19,-26,-25,28,2,13,-28,27,-9,19,15,-2,-19,-6,18,17,15,8,12,-23,-9,25,14,-18,18,15,24,23,-23,-10,3,22,-18,-2,-14,3,-4,28,22,29,-18,19,19,-30,4,13,24,-19,-17,-11,-20,14,-25,-25,27,25,-16,-10,-27,23,-2,10,29,-30,7,-5,-10,-9,2,-10,8,-25,-11,23,-23,15,-16,-25,-8,-10,-7,-27,10,10,-19,13,8,-7,21,-23,21,-14,-18,24,9,24,19,-28,8,-16,-16,-6,24,-1,9,17,2,-26,9,-2,-16,18,29,-24,8,-24,29,-24,5,-21,-7,-5,6,25,18,-13,-11,-13,-17,24,-5,12,-1,-27,-18,18,17,-12,-20,2,24,-25,21,18,10,16,12,-20,-8,0,1,1,-1,24,11,-25,24,-20,21,-15,-25,-7,10,-22,-30,15,-19,-11,-17,-20,25,0,-16,-15,5,6,-22,6,28,27,24,-4,-12,-16,5,20,-12,21,-26,-25,14,-16,23,10,19,-13,10,3,-30,-26,1,-27,-29,26,9,-22,-24,-30,3,-9,3,-23,23,-7,15,-4,-19,7,-7,-22,12,3,16,18,22,-5,-24,5,-30,-18,12,22,-24,24,0,-25,3,-30,-14,22,-18,-30,-24,-12,17,-1,-30,-7,-24,-26,-14,-18,12,-7,-10,13,21,9,15,28,-6,-8,-16,-7,-8,23,-2,8,-9,11,-19,25,-22,27,-27,-2,-8,-18,20,-9,25,-5,-9,-14,24,25,13,-10,-4,22,-25,-21,-14,20,-22,10,-15,8,-1,11,16,-1,-24,-19,29,-10,5,27,-10,-3,10,-14,-18,-16,8,-6,3,-10,24,25,-1,-16,-21,18,26,-5,12,-5,-30,-18,5,-16,26,26,-7,-7,-11,-1,-21,-22,-17,-4,-13,17,-23,-16,-2,12,-2,29,-13,26,-26,-6,-7,-23,-1,16,1,-21,-12,-15,-22,14,-26,-10,8,0,11,15,-11,-1,-27,-23,27,-2,19,-5,3,-10,-29,10,-28,-27,-20,-8,28,21,-24,-4,-29,-11,-13,-27,-19,13,-29,29,22,-9,-5,20,22,27,-6,-22,20,11,0,25,16,24,-24,4,8,2,-18,18,-12,22,-14,-13,18,-13,-29,10,-19,2,25,11,-5,-1,-24,8,18,-27,17,-21,15,-10,0,-17,29,-27,0,16,14,5,-12,8,-27,11,23,1,27,27,-29,13,-28,4,0,1,10,22,27,10,1,-26,-22,-2,7,-15,10,11,26,1,0,6,15,-11,6,15,7,4,13,17,10,6,-27,-16,5,11,1,-9,23,-11,5,14,-29,-7,-18,21,22,-19,7,27,-8,29,-9,21,18,-28,0,1,26,-26,-28,28,-30,-20,-17,9,-8,-4,-29,-3,-1,12,7,16,24,-6,4,-12,24,10,-29,-14,-27,-12,9,2,-4,20,5,-20,-27,-8,-6,-7,12,21,-15,-21,4,-10,14,-14,-2,-17,12,-8,8,-26,24,24,10,-24,-2,8,-30,-10,6,0,-28,10,10,11,26,-2,29,13,-21,-7,-7,-14,-9,26,2,7,-5,6,23,-9,-13,-4,18,-19,-21,3,19,-23,-16,16,-9,-7,-24,7,-25,-26,-12,5,-12,20,11,24,5,3,16,-25,-20,16,27,16,7,16,21,-7,27,11,16,-17,-8,-11,13,-2,7,27,-28,1,-9,-7,0,21,-5,13,6,2,-13,-28,-29,-2,19,24,-27,-17,13,26,-10,-28,-6,29,-27,-24,3,-23,23,-10,26,6,21,29,20,-15,8,8,11,-3,-19,-18,13,2,24,-18,-4,-20,-30,5,-27,-5,-30,-19,-1,-20,5,-23,9,-1,28,14,-28,7,-25,-29,8,-20,17,8,-1,8,15,-6,-13,-6,7,-25,-19,-25,17,28,-6,-17,-27,-11,-13,-8,16,4,25,29,26,6,6,-22,1,-5,-20,8,-9,21,-9,22,25,16,-29,-25,20,-18,-12,14,19,-30,-23,24,-9,3,-3,0,3,19,-7,-30,3,21,-1,3,7,-27,-4,-8,-2,-6,-16,-22,14,-10,-9,13,23,26,12,-7,11,8,-21,-25,24,-12,17,13,-30,-5,-17,14,9,-13,8,5,2,-16,-1,4,-30,-21,5,-8,8,-10,0,-20,8,27,26,-28,-22,-13,-7,-7,8,15,3,2,8,17,-20,22,18,-15,-29,5,-30,10,-6,0,15,21,6,14,-17,21,14,1,-29,-2,-4,-30,27,-7,-22,9,-12,-8,-20,-23,2,-1,-28,24,-24,-10,-6,-30,10,-27,17,-7,-10,7,-9,18,-24,-13,13,26,25,-21,-16,28,-25,-1,25,7,-18,-28,-5,-5,27,10,10,10,-26,-5,12,-11,-1,-1,-16,-7,29,26,-7,-12,22,-4,-20,-11,-12,-3,26,-7,14,-20,25,-29,-21,22,-28,23,-29,-2,11,-18,-9,7,26,-30,12,-6,19,10,25,-12,-14,2,26,4,0,-27,17,-28,4,10,-29,6,-9,-3,-20,-29,20,-17,-20,7,20,-6,1,-10,-30,-23,10,-13,9,27,-1,-24,-27,10,4,-25,-7,-10,-28,4,-20,7,-22,-20,-1,13,-1,-18,-30,16,23,20,10,-23,19,-27,26,17,4,-26,8,-24,29,-4,19,0,3,-15,23,8,17,14,-19,16,8,-19,8,4,-15,-13,-22,17,-29,-5,28,-24,25,3,-6,10,-25,-17,26,29,-27,0,14,-22,28,14,18,23,17,6,-12,8,29,7,12,17,-17,-1,12,27,26,7,-11,17,10,-3,-4,-6,10,2,-25,-14,25,-12,-3,-22,-26,21,-7,-20,22,-13,-12,-17,28,0,-7,7,15,26,-23,-22,-24,27,4,-19,4,26,-10,-17,10,-17,-11,27,-14,13,24,28,29,-12,-3,-3,9,9,-15,-5,2,-2,0,28,23,-26,-24,10,-22,25,18,-19,-2,-14,15,26,-29,-6,6,-7,29,-1,-28,29,6,-19,6,12,-17,-4,-5,-30,22,-13,-3,-24,-3,17,-11,-26,3,19,19,-4,16,2,24,2,-20,27,23,27,-19,13,-20,29,-7,-27,-4,16,18,5,6,29,-7,-28,-25,-7,-1,-1,8,11,24,-30,-18,14,-10,-27,-13,8,29,13,-4,-23,-3,3,-28,28,21,16,18,-27,24,16,19,11,-6,-7,3,16,-24,-5,6,12,-3,26,-3,23,12,-24,22,16,-21,6,-19,-9,3,21,-20,5,23,-18,-2,-21,-29,-8,-23,-19,18,22,-27,-2,-9,5,14,-26,13,19,-6,7,-30,-2,9,-19,-26,-24,-15,-27,-3,8,9,-7,22,-21,-30,6,9,25,13,19,8,-1,-3,-18,14,-10,9,-7,0,1,6,23,-4,3,18,-20,-19,24,10,-21,29,-4,6,-28,7,11,22,-1,-4,20,6,-28,1,15,-17,-4,-1,17,-11,-4,-16,16,-4,9,-14,-28,-29,17,0,18,-22,-22,-30,8,-21,-23,-6,26,20,-11,-30,4,-9,-23,-8,-28,18,-20,-16,-10,4,-16,-2,16,-18,-5,-12,0,23,-1,-12,-9,-11,21,7,-16,-19,-19,-10,12,-10,-12,21,21,-5,22,-14,-27,27,-10,-8,10,-23,21,-24,20,-30,20,-30,12,-5,3,9,17,1,-13,10,28,7,11,-13,16,1,4,3,-20,19,6,-6,9,2,15,19,25,-15,-2,-2,10,25,20,-20,-1,-19,-7,26,-8,0,-2,18,-22,29,8,-6,-4,-19,-11,3,20,21,-22,-19,-27,-13,-19,1,21,-5,28,7,12,-13,15,-17,18,-17,-16,-28,10,12,-10,15,-5,7,8,22,6,-26,19,-11,-10,24,10,-25,22,-18,-30,17,-23,-5,-5,4,-8,28,-6,-7,23,-28,13,26,-22,10,-15,-7,-7,10,3,16,4,-16,-29,12,-11,13,-11,-9,-10,10,5,25,-14,9,10,-20,-28,15,-17,-25,9,-15,-20,-3,-24,-19,-24,24,-21,9,0,-16,-4,-6,-21,-2,-27,14,-28,5,-26,12,-6,-8,-22,-10,14,0,29,5,16,5,-23,1,-8,24,-5,-16,12,27,-26,4,4,-11,-29,-27,-3,10,-9,-11,18,-17,-22,-4,-23,-22,-27,4,27,7,-21,-6,0,-28,-18,0,-2,-24,-11,2,0,0,1,-5,18,-24,1,1,0,4,27,5,1,-2,22,2,22,-9,29,-22,4,6,-6,-22,-5,-6,-7,-30,-23,21,20,-4,16,-14,-28,7,-5,-20,10,-3,8,-20,19,-29,18,24,2,21,-22,-9,-28,9,-30,-3,2,24,29,16,-8,-16,-29,26,25,22,16,-23,-20,-9,-21,-6,6,-21,13,29,-19,-26,-8,29,-27,2,-12,18,-2,19,9,-13,-25,2,-5,-13,-30,5,5,-17,16,23,12,-3,-15,24,-7,29,8,1,-4,1,-3,18,-3,8,9,5,-17,0,-14,19,4,16,17,-26,-1,-19,-24,-19,-18,9,-23,13,24,-1,-11,-24,14,29,-10,12,15,11,-30,-17,18,2,-28,-2,-19,13,-20,29,28,-27,19,24,7,-8,13,24,-4,8,4,-2,-15,17,22,-3,18,-20,-9,-28,-8,19,-4,18,7,-26,-8,29,-22,-27,5,18,12,22,3,22,-11,-2,-18,-25,4,-9,13,15,18,4,12,3,-11,-16,-2,16,-10,13,28,18,-9,-7,23,-27,12,9,25,4,18,2,-25,15,3,25,2,21,18,-30,8,-4,-5,-28,10,20,-14,25,29,2,5,-7,-11,11,23,-18,22,-29,24,-5,-2,-30,11,-3,-3,-10,17,23,1,-9,-7,-6,-19,-4,-4,17,-8,18,9,-28,14,-24,25,23,20,-11,10,-10,1,27,27,24,-6,21,-30,8,27,-20,5,-2,-12,-1,14,-17,15,0,5,23,-13,4,28,-24,18,-5,-18,-12,16,5,-15,1,0,21,0,-16,9,3,5,-5,-2,-12,-16,-3,-6,11,-20,12,20,13,6,27,-14,-22,-3,-14,-23,-6,-7,10,-27,-22,12,-18,-21,-24,27,-1,13,7,5,-15,10,-24,15,-25,4,10,12,6,-30,4,-4,15,-10,-7,4,-19,3,-13,17,10,-8,-24,-9,17,26,26,28,2,-23,5,6,27,23,14,25,22,-11,25,18,4,6,-28,-23,-20,-26,4,11,-2,28,4,-15,-20,12,-28,-27,-17,29,-19,3,-13,22,29,-1,0,9,-5,-19,-23,25,26,21,-21,-3,12,-13,27,2,-13,-28,-23,-16,-14,23,-16,2,1,15,-8,-12,-19,-16,-25,10,0,-12,21,-16,7,26,23,25,-5,27,-6,5,-13,-3,2,15,-30,7,-3,7,1,15,15,-11,-9,20,-13,-18,28,8,23,-15,13,-13,5,-5,-2,-11,2,-20,16,9,-26,-5,-18,-1,-2,-28,-6,-10,-5,-20,-8,3,-17,-27,26,-7,4,9,12,-10,21,-2,-19,-6,25,-4,15,-13,17,18,-17,10,6,23,0,17,-8,-3,10,-29,6,29,24,20,21,23,-25,22,0,-21,-17,29,19,-7,-22,-2,25,-15,24,-15,-24,-16,6,-24,7,-7,27,28,14,-29,18,-14,26,28,-18,-13,10,26,9,18,7,-27,-18,-17,3,11,2,10,-28,-16,-13,13,27,10,-24,-1,-7,-16,21,-26,-26,-14,11,-27,5,-5,-12,-25,24,19,16,-2,16,0,16,0,7,15,-23,-5,10,-21,24,25,-14,3,14,-11,-10,14,27,-15,22,-7,24,9,-28,-12,-6,12,0,13,-19,6,-24,26,28,10,13,-11,21,1,20,-17,-3,4,17,23,18,-4,21,26,9,8,16,16,-3,1,17,-16,-2,-30,-29,-24,-5,-19,-30,20,9,-14,-1,-10,-24,16,-11,-12,4,-6,24,-25,22,-15,24,15,-9,23,7,19,-6,-21,-4,-5,2,21,3,-15,18,24,-5,-2,-28,-7,-4,-10,-27,-9,22,-26,-17,-4,-29,10,-10,-17,-21,-10,24,-26,-6,27,8,-24,25,25,-17,-7,2,-17,18,3,-10,24,-3,-6,23,-1,-28,-14,-13,-23,-29,8,26,-24,20,-9,-4,24,18,22,-17,24,-2,16,14,-26,9,-29,-6,3,-4,5,-20,25,24,17,-30,-1,26,19,-21,17,-17,4,29,22,-30,17,16,-25,-21,-19,29,17,-16,-10,-14,-30,15,5,29,16,7,19,-4,-21,-16,-26,-12,-6,22,-28,-21,-18,2,-22,-20,-21,19,8,-27,-24,-28,29,3,10,-9,23,-21,16,27,9,14,6,27,5,-17,4,-6,-23,16,-17,-24,5,2,-8,3,-12,-9,-12,12,-19,-29,23,-20,13,3,-28,14,26,25,-2,-9,-26,-8,-18,-11,-30,9,10,18,-25,20,18,25,4,-11,14,23,-19,-18,4,-1,28,1,28,-3,-23,-28,22,17,12,-15,18,0,4,-11,-29,12,27,1,-25,16,-6,-5,12,-1,-21,-17,6,2,2,-11,19,22,8,0,-5,29,-23,-18,28,24,-23,-6,14,-23,16,12,2,20,-28,7,1,-17,-12,-15,24,0,-22,-3,26,15,-7,-27,-14,20,-10,-9,-17,-23,-11,17,-9,0,-23,26,4,-12,20,8,-10,-15,-20,12,-2,1,-16,14,-29,16,-5,-30,-5,-12,4,4,-23,-14,-23,15,-10,-12,22,5,-18,4,-1,6,29,7,-10,27,12,-8,-24,12,-5,-12,14,-10,20,13,8,23,-15,11,21,7,-14,15,11,3,-9,-20,14,-15,-14,4,-8,20,-10,-21,9,-16,-29,12,4,-26,-16,-11,-22,-23,-9,29,-11,-5,-4,21,6,-18,19,-29,-22,-16,-27,-13,-29,-13,-26,5,19,16,9,20,29,15,-13,-15,3,-18,25,-13,-28,10,-3,-25,20,-13,-12,-18,-10,6,-28,14,10,1,9,26,0,-30,-14,-10,25,-7,27,-18,-14,24,21,-1,-18,26,1,16,29,7,9,-20,23,-26,17,-7,21,13,-4,-23,-28,-17,0,1,9,2,27,15,-6,-16,23,-8,-8,19,24,-1,20,-21,18,26,-12,-8,20,-1,-22,29,23,7,-20,-7,11,27,20,-22,8,24,22,-13,-23,8,2,24,-13,-25,-1,-20,-4,12,-21,-8,-21,22,0,15,-3,24,14,20,6,21,-15,-16,26,24,-2,-3,10,-6,8,9,-14,-26,20,-22,10,7,-8,11,18,-29,4,-2,-13,0,19,29,-8,-17,7,6,9,12,-22,-4,-12,16,-3,4,6,8,-3,21,4,-28,-24,-7,-29,20,26,-24,-6,-30,22,-16,4,-21,9,-10,-22,28,-7,-25,6,-21,-22,7,-22,24,-26,16,20,18,-5,-23,19,22,-16,10,4,10,-27,-29,-10,-13,7,7,28,-23,8,14,14,16,11,-8,27,-28,-23,15,-14,-9,-12,1,-21,8,-11,-6,10,16,-18,-20,-17,4,5,8,-12,-3,8,-30,16,-16,-15,13,-27,18,6,-27,-2,-19,23,26,-13,10,-11,-2,1,-19,11,-4,-19,11,18,8,21,15,6,-29,0,17,-23,3,-24,13,-3,19,10,7,-30,1,-23,8,-20,14,-13,23,26,-12,25,7,1,-1,-7,-26,6,21,-25,-29,-4,0,-3,-19,17,10,28,-5,-13,-15,-7,9,22,17,-23,5,-7,29,26,-20,6,-14,18,-24,8,-28,21,-27,-8,-8,-25,-24,-4,-13,27,0,4,4,-20,16,-25,-3,19,-30,19,-20,10,2,-16,21,-20,-16,-9,29,-22,-19,14,21,2,-11,17,-23,-2,1,4,-16,-25,23,12,28,-12,18,1,24,15,6,24,3,-12,13,-1,-15,-14,12,14,28,27,-11,17,-9,27,-3,16,7,28,-25,14,-29,8,27,-17,27,8,-10,9,-13,-30,-17,6,13,-13,-17,-15,20,20,22,22,20,10,22,-8,-1,-8,-23,22,-18,-19,-14,-7,-15,3,21,26,-7,24,24,11,20,-1,-17,-3,-17,-29,-8,6,16,0,-12,-16,12,-5,-30,-5,-9,-2,10,-14,-1,16,-22,-7,-24,-25,8,28,-3,27,16,8,-8,-6,9,13,20,-29,12,-14,-8,13,-18,0,-7,-22,-30,26,-24,4,6,18,14,-1,3,-17,-27,-16,1,-26,-28,-13,29,-2,-16,8,10,-3,-15,-27,-2,-3,-24,-12,18,-30,18,3,26,-7,-17,14,-29,16,-26,-8,12,-15,-4,7,-9,0,25,22,-12,-21,6,-23,12,-23,1,-24,-16,24,0,-25,18,-11,-12,2,25,-16,6,-3,1,-28,27,25,22,-19,26,11,-30,-10,12,-19,-7,-18,-4,11,29,3,-27,15,-24,6,8,-26,-23,21,26,-29,4,0,23,9,6,-20,11,-28,25,5,25,29,2,-5,2,-23,0,-24,16,12,-24,-23,-11,-21,10,18,7,16,-24,4,17,-27,24,4,-16,9,-12,-2,-21,-2,-27,23,11,-24,3,11,-21,16,-8,-17,-28,-16,-6,-4,-21,-4,-20,-30,-29,5,-11,8,-15,18,-6,-12,-1,-3,-30,14,-14,4,21,-18,2,-24,-10,28,6,3,-1,20,18,18,-10,-13,-30,15,-4,26,15,-7,22,21,29,8,1,-16,15,-11,-19,-23,-27,0,18,27,20,-2,-14,-24,-24,-22,27,0,8,26,12,-25,-8,-10,-21,16,-17,-15,15,-7,-19,-23,-12,-20,11,-14,15,23,7,15,-4,-4,15,21,-20,19,-11,8,-27,18,-23,-27,-16,-28,18,-19,13,29,-13,-3,-22,26,26,19,-2,24,-19,20,10,12,9,-11,-9,10,-15,2,7,-21,-29,11,12,14,-28,18,-21,-11,11,-6,-22,22,-9,12,-7,-3,28,19,16,25,16,26,-6,23,-26,5,-13,26,-8,20,-14,-30,13,-14,10,12,-13,21,28,3,27,-4,-6,6,4,14,-17,-11,6,-23,-18,29,11,-28,-3,29,24,-19,-25,-1,-14,24,4,20,-19,8,-23,-8,-7,-21,-5,-22,-21,-9,16,17,4,20,-23,27,5,21,-9,22,-28,27,-11,9,-5,28,0,-7,26,9,18,7,-17,-17,18,-9,-26,8,20,13,-13,-6,25,27,-4,-23,17,14,28,19,1,3,-6,-2,5,5,28,-23,6,-20,-9,-9,-26,13,-16,-3,12,-1,-3,15,-16,13,-2,-9,-15,16,0,29,-15,0,20,-13,26,-12,9,1,18,22,19,22,-19,20,7,-18,-25,-14,-16,7,-19,-18,20,20,-2,2,13,16,11,8,12,-15,-12,15,28,17,27,-2,-7,-11,2,7,-17,-7,20,18,-19,28,2,24,22,-2,-13,11,-6,7,-22,-1,15,-22,-19,-8,21,-20,23,15,17,-16,7,-25,9,-11,-1,-26,4,23,-11,-7,8,-10,-27,20,22,0,11,-10,3,21,5,-19,21,22,-11,19,1,15,21,6,14,2,24,5,19,14,0,16,7,0,-14,28,-2,-30,-26,-11,9,14,21,-25,3,-30,-18,28,-17,-22,4,28,13,5,10,5,4,-27,-20,-21,10,-25,-26,0,24,-4,-24,5,26,7,0,-19,19,4,13,10,-22,16,5,19,27,-13,26,29,-3,-29,-10,15,10,19,28,9,-30,20,-28,-9,10,-1,-26,-21,8,-30,-20,-19,-5,-15,-30,16,20,-14,27,-17,-8,8,6,10,-6,8,-22,-26,-11,10,-12,-17,3,-10,-14,-15,-18,29,6,-1,-24,6,1,17,-18,15,-2,24,-3,-7,18,-12,28,27,25,-11,18,0,-27,11,21,-5,-24,29,29,-19,24,-22,-17,14,-2,-17,-10,20,7,24,-29,-19,-1,13,-19,-21,-12,-15,-1,-29,27,-9,-5,-20,-9,10,-19,14,11,-17,-4,-9,3,-23,-22,-23,-5,-7,2,-13,-6,-29,-21,-14,13,9,12,24,-7,7,26,20,16,-27,-29,-21,28,-18,-19,-9,-6,26,-23,-10,10,22,-26,-12,16,-1,8,15,-13,-3,1,20,18,15,6,22,27,14,-15,-19,-4,-18,20,-23,-19,12,-2,18,-19,-15,-22,-6,1,23,-4,-23,-1,-17,4,-7,9,-24,-2,-23,-4,-16,-5,24,12,9,-25,16,-30,18,28,-13,-11,-29,-4,-17,-8,11,4,-2,21,-22,27,-10,2,-24,-14,-24,-20,17,17,2,-12,26,-4,-21,3,-7,20,3,-28,-7,25,21,-7,20,-10,29,-14,3,27,-14,-16,12,-28,25,-30,15,26,4,-12,-17,-29,3,14,7,-17,29,21,5,18,-1,15,15,13,1,-17,27,-23,-22,29,-30,-5,3,20,-20,-10,-5,-25,22,-8,2,-6,16,-17,-20,-10,-22,-19,-10,-28,14,-26,0,-14,-15,-10,-2,25,4,12,9,23,13,29,28,13,15,-6,28,-19,-30,24,-30,-11,29,-18,-7,8,19,-22,21,26,24,-30,6,24,1,-5,-23,-14,10,11,25,21,-27,-13,-22,-7,-19,-20,24,-21,0,2,-30,17,-27,20,-10,27,22,-5,14,18,-17,-18,17,8,9,-29,4,-17,-30,12,-29,-26,20,6,-4,-30,13,-21,-9,-9,-29,-29,29,-21,-15,-4,19,0,15,18,-15,-27,6,-15,-11,-21,28,4,-18,-26,7,-8,-9,24,0,-25,2,27,-28,23,9,3,15,9,-20,22,5,-2,28,-5,-2,-4,-12,6,-10,-28,2,17,14,-11,-20,-27,2,-30,-30,29,0,12,1,-27,-6,21,-6,-29,16,13,21,22,25,-1,-28,-9,24,10,-16,9,-26,15,-20,-10,23,-2,5,-16,-9,-5,-10,6,4,-10,8,-1,22,29,-14,-19,26,19,-16,-25,-8,-17,-3,-22,3,26,-21,2,19,0,-14,25,-12,-22,2,-27,9,-14,-20,11,8,6,-13,29,17,-26,4,15,6,4,-5,-6,-22,-3,-19,18,-23,-26,-28,22,13,-2,-14,27,-25,-1,10,-22,1,-11,19,3,-23,-30,-29,-1,6,-27,22,26,-18,-18,29,22,-3,-22,21,20,13,-16,-12,-28,-28,19,22,20,10,20,5,18,-17,24,-15,-20,-11,-12,-16,-11,-17,-19,6,18,-4,-6,19,-13,-1,5,6,-21,-8,22,18,-4,-9,19,15,-24,24,-27,16,-10,-9,4,-3,-4,-14,10,21,24,-18,-30,17,3,11,13,7,-2,-15,7,-10,-15,16,-6,22,-1,6,-13,-10,-21,-11,22,19,-8,-24,-23,2,-28,-25,22,-6,-4,-9,-26,-13,4,15,9,1,-10,-18,11,26,-28,-14,-22,-15,23,-25,-9,17,-20,25,-21,8,14,6,-2,-22,-25,-24,-17,23,-1,-29,18,16,-17,-28,-12,16,-5,-21,-14,6,25,-21,28,11,19,0,-6,-23,-28,-28,-8,-19,12,-25,11,3,3,-7,-4,29,-17,6,-19,24,14,-17,-12,-16,-27,24,7,17,24,-30,-10,-18,-20,-2,-12,-22,3,3,13,22,-4,-3,21,-2,14,27,-21,-16,-29,20,21,15,25,26,15,5,-7,-12,11,5,-3,11,7,-3,11,-8,-22,-13,-15,-24,-10,14,-24,12,-16,28,9,4,23,27,-13,28,2,21,-2,11,-25,-12,14,-4,13,-23,3,-2,-13,-15,-15,-25,4,22,-15,-23,7,17,27,14,19,-29,-24,14,3,-18,7,-9,-11,-22,11,17,-18,9,8,16,6,-24,-13,19,25,12,-30,-1,21,-26,-27,17,-8,-21,-30,-3,19,4,-6,-24,1,26,-16,17,-19,-23,-26,-8,15,-5,28,7,-23,-24,9,-13,-5,-23,8,27,6,26,-17,4,-26,-10,-9,-3,-9,-9,1,22,4,6,21,29,27,-12,-27,-24,-3,-14,-7,-10,-13,3,1,-24,0,-15,-27,-4,-26,-24,4,-14,-5,-21,-24,28,-8,27,-25,4,-8,14,-9,-28,-21,-15,16,-11,10,19,-9,17,16,-18,-21,24,8,-9,20,-26,-6,-30,27,24,8,-28,-24,-16,29,-30,25,18,-3,3,-3,1,12,-26,1,-28,25,-27,14,-17,-1,-22,26,10,-17,28,-15,-8,-7,-18,-22,4,1,-8,20,-15,-17,11,-25,17,2,0,26,-7,14,-23,-30,-5,18,4,15,-27,-4,-23,-25,6,-16,-1,-19,-1,12,18,-5,16,-25,-4,15,-4,21,-23,-16,3,-19,-2,17,4,2,-1,0,20,24,13,17,-18,29,0,26,24,13,-4,7,19,22,-17,11,19,8,3,13,5,-16,-22,25,2,17,24,-1,5,16,16,-21,14,-3,28,20,-28,-17,-22,-1,-16,-27,-24,11,7,-4,-3,-23,9,-15,5,-22,-24,-21,-8,-2,29,26,26,26,-30,-21,-24,-25,5,-8,-25,8,5,-24,25,-15,-17,-8,18,13,12,5,-24,23,-2,3,3,11,0,19,8,23,12,12,29,5,-12,20,15,19,5,29,-24,22,-11,16,4,-11,16,-30,7,-2,9,2,-13,11,-14,-28,-23,-9,18,12,-13,0,7,27,-15,-24,-26,-30,0,-24,-29,28,-5,1,-3,10,7,-29,18,11,10,-7,0,-5,16,22,-14,9,9,-18,14,-28,-1,-28,23,-17,12,4,10,26,5,26,5,21,23,-6,9,-5,-11,-29,-13,20,19,-2,-9,11,-10,-16,24,-5,-2,-8,-29,18,-27,4,6,28,-28,-24,21,19,29,-19,13,4,20,23,1,14,27,-19,6,-29,-5,-14,14,-6,24,25,-22,28,-3,-22,18,-24,28,24,18};
    //int lower = -24, upper = 30;
    
    
    int r0 = sol.countRangeSum0(nums, lower, upper);
    cout << "brute force: \n" << r0 << "\n\n";
    
    int r1 = sol.countRangeSum1(nums, lower, upper);
    cout << "Binary Search with vector: \n" << r1 << "\n\n";
    
    int r2 = sol.countRangeSum2(nums, lower, upper);
    cout << "Binary Search with multiset: \n" << r2 << "\n\n";
    
    int r3 = sol.countRangeSum3(nums, lower, upper);
    cout << "Binary Search Tree: \n" << r3 << "\n\n";
    
    int r4 = sol.countRangeSum4(nums, lower, upper);
    cout << "MergeSort: \n" << r4 << "\n\n";

    return 0;
}