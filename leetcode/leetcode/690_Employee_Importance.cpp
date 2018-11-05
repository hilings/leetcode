//
//  690_Employee_Importance.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 // Employee info
 */
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
    Employee(int x, int y, vector<int> z) : id(x), importance(y), subordinates(z) {};
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> um;
        for (Employee* e: employees) {
            um[e->id] = e;
        }
        vector<Employee*> q {um[id]};
        int r = 0;
        while (!q.empty()) {
            Employee* e = q.back();
            q.pop_back();
            r += e->importance;
            for (int sub: e->subordinates) {
                q.push_back(um[sub]);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 690. Employee Importance, C++ ...\n\n";
    Solution sol;

    vector<Employee*> employees{
        new Employee(1, 5, {2, 3}),
        new Employee(2, 3, {}),
        new Employee(3, 3, {})      // 1
    };
    int id = 1;

    int r = sol.getImportance(employees, id);
    cout << r << '\n';

    return 0;
}
