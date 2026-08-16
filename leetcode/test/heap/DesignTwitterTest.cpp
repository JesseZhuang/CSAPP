#include "gtest/gtest.h"
#include "heap/DesignTwitter.hpp"

TEST(heap, design_twitter) {
    // Test 1: LeetCode example
    {
        Twitter tw;
        tw.postTweet(1, 5);
        auto feed = tw.getNewsFeed(1);
        ASSERT_EQ(vector<int>{5}, feed);

        tw.follow(1, 2);
        tw.postTweet(2, 6);
        feed = tw.getNewsFeed(1);
        ASSERT_EQ((vector<int>{6, 5}), feed);

        tw.unfollow(1, 2);
        feed = tw.getNewsFeed(1);
        ASSERT_EQ(vector<int>{5}, feed);
    }

    // Test 2: Empty feed
    {
        Twitter tw;
        auto feed = tw.getNewsFeed(1);
        ASSERT_TRUE(feed.empty());
    }

    // Test 3: Max 10 tweets
    {
        Twitter tw;
        for (int i = 1; i <= 15; i++)
            tw.postTweet(1, i);
        auto feed = tw.getNewsFeed(1);
        ASSERT_EQ(10u, feed.size());
        // Most recent first: 15, 14, ..., 6
        for (int i = 0; i < 10; i++)
            ASSERT_EQ(15 - i, feed[i]);
    }

    // Test 4: Follow self (no duplicates)
    {
        Twitter tw;
        tw.postTweet(1, 100);
        tw.follow(1, 1); // should be no-op
        auto feed = tw.getNewsFeed(1);
        ASSERT_EQ(vector<int>{100}, feed);
    }

    // Test 5: Unfollow non-followee (no error)
    {
        Twitter tw;
        tw.unfollow(1, 2); // should not crash
        tw.postTweet(1, 10);
        auto feed = tw.getNewsFeed(1);
        ASSERT_EQ(vector<int>{10}, feed);
    }

    // Test 6: Multiple users interleaved
    {
        Twitter tw;
        tw.postTweet(1, 1);
        tw.postTweet(2, 2);
        tw.postTweet(3, 3);
        tw.postTweet(1, 4);
        tw.postTweet(2, 5);
        tw.postTweet(3, 6);

        tw.follow(1, 2);
        tw.follow(1, 3);

        auto feed = tw.getNewsFeed(1);
        // All 6 tweets visible to user 1, most recent first: 6,5,4,3,2,1
        ASSERT_EQ((vector<int>{6, 5, 4, 3, 2, 1}), feed);

        // User 2 only sees own tweets
        auto feed2 = tw.getNewsFeed(2);
        ASSERT_EQ((vector<int>{5, 2}), feed2);
    }
}
