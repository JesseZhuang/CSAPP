#include "gtest/gtest.h"
#include "heap/MedianFinder.hpp"

TEST(heap, median_finder) {
    // Test Two Heaps approach
    {
        MedianFinderHeap mf;
        mf.addNum(1);
        ASSERT_DOUBLE_EQ(1.0, mf.findMedian());
        mf.addNum(2);
        ASSERT_DOUBLE_EQ(1.5, mf.findMedian());
        mf.addNum(3);
        ASSERT_DOUBLE_EQ(2.0, mf.findMedian());
    }
    {
        MedianFinderHeap mf;
        mf.addNum(6);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(10);
        ASSERT_DOUBLE_EQ(8.0, mf.findMedian());
        mf.addNum(2);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(6);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(5);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
    }
    {
        MedianFinderHeap mf;
        mf.addNum(-1);
        mf.addNum(-2);
        mf.addNum(-3);
        ASSERT_DOUBLE_EQ(-2.0, mf.findMedian());
        mf.addNum(-4);
        ASSERT_DOUBLE_EQ(-2.5, mf.findMedian());
    }

    // Test Multiset approach
    {
        MedianFinderMultiset mf;
        mf.addNum(1);
        ASSERT_DOUBLE_EQ(1.0, mf.findMedian());
        mf.addNum(2);
        ASSERT_DOUBLE_EQ(1.5, mf.findMedian());
        mf.addNum(3);
        ASSERT_DOUBLE_EQ(2.0, mf.findMedian());
    }
    {
        MedianFinderMultiset mf;
        mf.addNum(6);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(10);
        ASSERT_DOUBLE_EQ(8.0, mf.findMedian());
        mf.addNum(2);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(6);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
        mf.addNum(5);
        ASSERT_DOUBLE_EQ(6.0, mf.findMedian());
    }
    {
        MedianFinderMultiset mf;
        mf.addNum(-1);
        mf.addNum(-2);
        mf.addNum(-3);
        ASSERT_DOUBLE_EQ(-2.0, mf.findMedian());
        mf.addNum(-4);
        ASSERT_DOUBLE_EQ(-2.5, mf.findMedian());
    }
}
