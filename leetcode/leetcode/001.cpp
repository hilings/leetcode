//
//  001.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/1/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVector(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';
}

class Solution {
// sort, then scan from two ends
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> tmp = numbers;
        vector<int> result;
        int index1, index2;
        sort(tmp.begin(), tmp.end());
        
        for (int i = 0, j = (int) tmp.size() - 1; i < j; ) {
            if (tmp.at(i) + tmp.at(j) < target) {
                i++;
            } else if (tmp.at(i) + tmp.at(j) > target){
                j--;
            } else {
                index1 = (int)(find(numbers.begin(), numbers.end(), tmp.at(i)) - numbers.begin()) + 1;
                index2 = (int)(find(numbers.begin(), numbers.end(), tmp.at(j)) - numbers.begin()) + 1;
                if (index2 == index1) {
                    index2 = (int)(find(numbers.begin()+index1, numbers.end(), tmp.at(j)) - numbers.begin()) + 1;
                }
                break;
            }
        }

        result.push_back(index1);

        if (index1 > index2) {
            result.insert(result.begin(), index2);
        } else {
            result.push_back(index2);
        }
        return result;
    }
};

class Solution2 {
// put vector into map, then scan for pair
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mymap;
        vector<int> result;
        int index1, index2;
        
        for (int i = 0; i < numbers.size(); ++i) {
            mymap[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); ++i) {
            if (mymap.find(target - numbers[i]) != mymap.end()) {
                index1 = i + 1;
                index2 = mymap[target - numbers[i]] + 1;
                if (index1 < index2) {
                    break;
                }
            }
        }
        result.push_back(index1);
        result.push_back(index2);
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 001 Two Sum, C++ ... ...\n";
    
    int array[] = {3, 4, 2};
    vector<int> vec;
    vec.assign(array, array + sizeof(array) / sizeof(int));
    printVector(vec);

    Solution sol;
    printVector(sol.twoSum(vec, 6));

    Solution2 sol2;
    printVector(sol2.twoSum(vec, 6));

    return 0;
}