//
//  355.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

class Twitter {
    unordered_map<int,map<int,int>> tweets;
    unordered_map<int,unordered_set<int>> followings;
    long timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        cout << userId << " posting " << tweetId << '\n';
        tweets[userId][++timestamp] = tweetId;
        follow(userId, userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        cout << "getting tweet for " << userId << ": ";
        map<int,int> m;
        for (int f: followings[userId]) {	// each followee
            int count = 0;
            for (auto it = tweets[f].rbegin(); it != tweets[f].rend() && count < 10; it++) {	// last 10 tweets per followee
                m[it->first] = it->second;
                count++;
                if (m.size() > 10) {
                    m.erase(m.begin());
                }
            }
        }
        vector<int> r;
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            r.push_back(it->second);
        }

        for (int a: r) {
            cout << a << ' ';
        }
        cout << '\n';
        return r;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        cout << followerId << " following " << followeeId << '\n';
        followings[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        cout << followerId << " unfollowing " << followeeId << '\n';
        if (followerId != followeeId) {
            followings[followerId].erase(followeeId);
        }
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 355. Design Twitter, C++ ...\n\n";

    /**
     * Your Twitter object will be instantiated and called as such:
     Twitter obj = new Twitter();
     */
    Twitter obj;
    /*
     obj.postTweet(1,1);
     obj.postTweet(1,4);
     obj.postTweet(1,7);
     obj.postTweet(1,10);
     obj.postTweet(1,13);
     obj.postTweet(2,2);
     obj.postTweet(2,5);
     obj.postTweet(2,8);
     obj.postTweet(2,11);
     obj.postTweet(2,14);
     obj.postTweet(3,3);
     obj.postTweet(3,6);
     obj.postTweet(3,9);
     obj.postTweet(3,12);
     obj.postTweet(3,15);

     vector<int> param_1 = obj.getNewsFeed(1);

     obj.follow(1,2);
     vector<int> param_2 = obj.getNewsFeed(1);

     obj.follow(1,3);
     vector<int> param_3 = obj.getNewsFeed(1);

     obj.unfollow(1,2);
     vector<int> param_4 = obj.getNewsFeed(1);
     */

    /*
     obj.postTweet(1,1);
     vector<int> param_5 = obj.getNewsFeed(1);
     obj.follow(2,1);
     vector<int> param_6 = obj.getNewsFeed(2);
     obj.unfollow(2,1);
     vector<int> param_7 = obj.getNewsFeed(2);
     */
    
    obj.postTweet(2,5);
    obj.postTweet(1,3);
    obj.postTweet(1,101);
    obj.postTweet(2,13);
    obj.postTweet(2,10);
    obj.postTweet(1,2);
    obj.postTweet(2,94);
    obj.postTweet(2,505);
    obj.postTweet(1,333);
    obj.postTweet(1,22);
    
    vector<int> param_8 = obj.getNewsFeed(2);
    obj.follow(2,1);
    vector<int> param_9 = obj.getNewsFeed(2);
    
    /*
     [null,
     null,null,null,null,null,
     null,null,null,null,null,
     [505,94,10,13,5],
     null,
     [22,333,505,94,2,10,13,101,3,5]]
     */
    
    return 0;
}
