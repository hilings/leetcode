//
//  407_trapping_rain_water_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/29/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) {
            return 0;
        }
        int m = heightMap.size(), n = heightMap[0].size(), sum = 0;
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        auto cmp = [&heightMap] (const pair<int,int>& a, const pair<int,int>& b) {
            return heightMap[a.first][a.second] > heightMap[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);	// highest on top

        // start from out boundary
        for (int j = 0; j < n; j++) {
            q.push({0,j});
            q.push({m-1,j});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        for (int i = 1; i < m-1; i++) {
            q.push({i,0});
            q.push({i,n-1});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }

        // push boundary inwards
        while (!q.empty()) {
            int i = q.top().first, j = q.top().second, bound = heightMap[i][j];
            q.pop();
            //printf("[%d, %d] = %d\n", i, j, heightMap[i][j]);

            for (pair<int,int> nb: vector<pair<int,int>> {{i,j-1}, {i,j+1}, {i-1,j}, {i+1,j}}) {
                int ii = nb.first, jj = nb.second;
                if (ii < 0 || ii == m || jj < 0 || jj == n || visited[ii][jj]) {
                    continue;
                }
                visited[ii][jj] = true;
                if (heightMap[ii][jj] < bound) {
                    //printf("adding %d\n", bound - heightMap[ii][jj]);
                    sum += bound - heightMap[ii][jj];
                    heightMap[ii][jj] = bound;
                }
                q.push(pair<int,int> (ii, jj));
            }
        }
        return sum;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 407. Trapping Rain Water II, C++ ...\n\n";
    Solution sol;
    
    vector<vector<int>> heightMap {
        //*
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}	// 4
        //*/
        
        /*
         {12,13,1,12},
         {13,4,13,12},
         {13,8,10,12},
         {12,13,12,12},
         {13,13,13,13}	// 14
         */
    };
    int r = sol.trapRainWater(heightMap);
    cout << r << '\n';
    
    return 0;
}
