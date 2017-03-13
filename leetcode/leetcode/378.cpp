//
//  378.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {	// priority_queue, see leetcode #373
        auto cmp = [&matrix](const pair<int,int>& a, const pair<int,int>& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        minHeap.push(pair<int,int> (0,0));

        while (!minHeap.empty() && --k) {
            pair<int,int> t = minHeap.top();
            //cout << matrix[t.first][t.second] << '\n';
            minHeap.pop();
            if (t.second+1 < (int)matrix[0].size())
                minHeap.push(pair<int,int> (t.first, t.second+1));
            if (t.second == 0 && t.first+1 < (int)matrix.size())
                minHeap.push(pair<int,int> (t.first+1, t.second));
        }
        return matrix[minHeap.top().first][minHeap.top().second];
    }

    int kthSmallest2(vector<vector<int>>& matrix, int k) {	// binary search, n*log(n)*log(n)
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int count = 0, mid = l + (r-l)/2;
            for (int i = 0; i < (int)matrix.size(); i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k) {
                l = mid+1;
            } else {
                r = mid;
            }
            //cout << "mid = " << mid << ", count = " << count << '\n';
        }
        return l;
    }

    /*------------------------------------*/
    int kthSmallest3(const vector<vector<int>>& matrix, int k) {	// O(n)
        if (k == 1) {	// guard for 1x1 matrix
            return matrix.front().front();
        }

        size_t n = matrix.size();
        vector<size_t> indices (n, 0);
        iota(indices.begin(), indices.end(), 0);
        array<size_t, 2> ks = { (size_t)k-1, (size_t)k-1 };	// use zero-based indices
        array<int, 2> results = biSelect(matrix, indices, ks);
        return results[0];
    }

    // select two elements from four elements, recursively
    array<int, 2> biSelect(const vector<vector<int>>& matrix, const vector<size_t>& indices, const array<size_t, 2>& ks) {
        // Select both ks[0]-th element and ks[1]-th element in the matrix,
        // where k0 = ks[0] and k1 = ks[1] and n = indices.size() satisfie
        // 0 <= k0 <= k1 < n*n  and  k1 - k0 <= 4n-4 = O(n)   and  n>=2
        size_t n = indices.size();
        if (n == 2u) {	// base case of resursion
            return biSelectNative(matrix, indices, ks);
        }

        // update indices
        vector<size_t> indices_;
        for (size_t idx = 0; idx < n; idx += 2) {
            indices_.push_back(indices[idx]);
        }
        if (n % 2 == 0) { // ensure the last indice is included
            indices_.push_back(indices.back());
        }

        // update ks
        // the new interval [xs_[0], xs_[1]] should contain [xs[0], xs[1]]
        // but the length of the new interval should be as small as possible
        // therefore, ks_[0] is the largest possible index to ensure xs_[0] <= xs[0]
        // ks_[1] is the smallest possible index to ensure xs_[1] >= xs[1]
        array<size_t, 2> ks_ = { ks[0] / 4, 0 };
        if (n % 2 == 0) {	// even
            ks_[1] = ks[1] / 4 + n + 1;
        } else {	// odd
            ks_[1] = (ks[1] + 2 * n + 1) / 4;
        }

        // call recursively
        array<int, 2> xs_ = biSelect(matrix, indices_, ks_);

        // Now we partipate all elements into three parts:
        // Part 1: {e: e < xs_[0]}.  For this part, we only record its cardinality
        // Part 2: {e: xs_[0] <= e < xs_[1]}. We store the set elementsBetween
        // Part 3: {e: e >= xs_[1]}. No use. Discard.
        array<int, 2> numbersOfElementsLessThanX = { 0, 0 };
        vector<int> elementsBetween;	// [xs_[0], xs_[1])

        array<size_t, 2> cols = { n, n };	// column index such that elem >= x
        // the first column where matrix(r, c) > b
        // the first column where matrix(r, c) >= a
        for (size_t row = 0; row < n; ++row) {
            size_t row_indice = indices[row];
            for (size_t idx: {0, 1}) {
                while ((cols[idx] > 0) && (matrix[row_indice][indices[cols[idx] - 1]] >= xs_[idx])) {
                    --cols[idx];
                }
                numbersOfElementsLessThanX[idx] += cols[idx];
            }
            for (size_t col = cols[0]; col < cols[1]; ++col) {
                elementsBetween.push_back(matrix[row_indice][indices[col]]);
            }
        }

        array<int, 2> xs; // the return value
        for (size_t idx: {0, 1}) {
            size_t k = ks[idx];
            if (k < numbersOfElementsLessThanX[0]) {	// in the Part 1
                xs[idx] = xs_[0];
            } else if (k < numbersOfElementsLessThanX[1]) {	// in the Part 2
                size_t offset = k - numbersOfElementsLessThanX[0];
                vector<int>::iterator nth = next(elementsBetween.begin(), offset);
                nth_element(elementsBetween.begin(), nth, elementsBetween.end());
                xs[idx] = (*nth);
            } else {	// in the Part 3
                xs[idx] = xs_[1];
            }
        }
        return xs;
    }

    // select two elements from four elements, using native way
    array<int, 2> biSelectNative(const vector<vector<int>>& matrix, const vector<size_t>& indices, const array<size_t, 2>& ks) {
        vector<int> allElements;
        for (size_t r: indices) {
            for (size_t c: indices) {
                allElements.push_back(matrix[r][c]);
            }
        }
        sort(allElements.begin(), allElements.end());
        array<int, 2> results;
        for (size_t idx: {0, 1}) {
            results[idx] = allElements[ks[idx]];
        }
        return results;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 378. Kth Smallest Element in a Sorted Matrix, C++ ...\n\n";
    Solution sol;
    
    vector<vector<int>> matrix {
        vector<int> { 1,  5,  9},
        vector<int> {10, 11, 13},
        vector<int> {12, 13, 15}
    };
    int k = 8;
    
    int r = sol.kthSmallest(matrix, k);
    cout << r << '\n';
    
    int r2 = sol.kthSmallest2(matrix, k);
    cout << r2 << '\n';
    
    int r3 = sol.kthSmallest3(matrix, k);
    cout << r3 << '\n';
    
    return 0;
}
