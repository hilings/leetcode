//
//  018.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/26/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > v;
        int size = (int)num.size();
        if (size < 4)
            return v;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < size - 3; i++) {
            if (i-1 >= 0 && num[i] == num[i-1])
                continue;
            
            for (int j = i + 1; j < size - 2; j++) {
                if (j-1 >= i+1 && num[j] == num[j-1])
                    continue;
                
                int p = j + 1;
                int q = size - 1;
                while (p < q) {
                    if (num[p] + num[q] < target-num[i]-num[j]) {
                        p++;
                    } else if (num[p] + num[q] > target-num[i]-num[j]) {
                        q--;
                    } else {
                        int a[4] = {num[i], num[j], num[p], num[q]};
                        vector<int> tv;
                        tv.assign(a, a+4);
                        v.push_back(tv);
                        while (p < q && num[p] == a[2])
                            p++;
                        while (p < q && num[q] == a[3])
                            q--;
                    }
                }
            }
        }
        cout << "\nSolving...\n";
        for (int i = 0; i < v.size(); i++) {
            printVector(v[i]);
        }
        return v;
    }
    
    vector<vector<int> > fourSum2(vector<int> &num, int target) {
        vector<vector<int>> v;
        int size = (int)num.size();
        if (size < 4)
            return v;
        
        unordered_map<int, vector<pair<int,int>>> h;
        
        for (int i = 0; i < size-1; i++)
            for (int j = i+1; j < size; j++)
                h[num[i]+num[j]].push_back(make_pair(i, j));
        
        for (unordered_map<int, vector<pair<int,int>>>::iterator it = h.begin(); it != h.end(); it++) {
            unordered_map<int, vector<pair<int,int>>>::iterator rit = h.find(target - it->first);
            if (rit == h.end())
                continue;
            
            for (int ii = 0; ii < it->second.size(); ii++) {
                for (int jj = 0; jj < rit->second.size(); jj++) {
                    if (it->second[ii].first == rit->second[jj].first || it->second[ii].first == rit->second[jj].second ||
                        it->second[ii].second == rit->second[jj].first || it->second[ii].second == rit->second[jj].second)
                        continue;
                    int ta[] = {num[it->second[ii].first], num[it->second[ii].second], num[rit->second[jj].first], num[rit->second[jj].second]};
                    sort(ta, ta+4);
                    vector<int> tv;
                    tv.assign(ta,ta+4);

                    if (find(v.begin(), v.end(), tv) == v.end())
                        v.push_back(tv);
                }
            }
        }
        cout << "\nSolving...\n";
        for (int i = 0; i < v.size(); i++) {
            printVector(v[i]);
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 018 4Sum, C++ ... ...\n";
    
    //int a[] = {1, 0, -1, 0, -2, 2};
    //int a[] = {0, 0, 0, 0};
    int a[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    
    
    //int target = 0;
    int target = -236727523;
    vector<int> num;
    int size = sizeof(a)/sizeof(int);
    num.assign(a, a+size);
    
    printVector(num);
    cout << "size = " << size << '\n';
    Solution sol;
    sol.fourSum2(num, target);
    
    return 0;
}