#ifndef LEETCODE_DESIGNTWITTER_HPP
#define LEETCODE_DESIGNTWITTER_HPP

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// leet 355 — Design Twitter
// HashMap + Heap (merge k sorted lists)
// postTweet: O(1), getNewsFeed: O(k log k) where k = number of followees,
// follow/unfollow: O(1)

class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets; // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> follows;   // userId -> set of followeeIds

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // priority_queue: (time, tweetId, userId, index in that user's tweet list)
        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        // Collect followees + self
        unordered_set<int> users;
        users.insert(userId);
        if (follows.count(userId))
            users.insert(follows[userId].begin(), follows[userId].end());

        for (int uid : users) {
            if (tweets.count(uid) && !tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                auto& [t, tid] = tweets[uid][idx];
                pq.push({t, tid, uid, idx});
            }
        }

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            auto [t, tid, uid, idx] = pq.top();
            pq.pop();
            feed.push_back(tid);
            if (idx > 0) {
                int ni = idx - 1;
                auto& [nt, ntid] = tweets[uid][ni];
                pq.push({nt, ntid, uid, ni});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId))
            follows[followerId].erase(followeeId);
    }
};

#endif //LEETCODE_DESIGNTWITTER_HPP
