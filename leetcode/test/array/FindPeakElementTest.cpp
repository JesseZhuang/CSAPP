#include "gtest/gtest.h"
#include "array/FindPeakElement.hpp"

namespace {
    // Helper: validates that the returned index is actually a peak
    auto isPeak = [](const vector<int>& nums, int idx) -> bool {
        if (idx < 0 || idx >= (int)nums.size()) return false;
        bool leftOk = (idx == 0) || (nums[idx] > nums[idx - 1]);
        bool rightOk = (idx == (int)nums.size() - 1) || (nums[idx] > nums[idx + 1]);
        return leftOk && rightOk;
    };
}

TEST(array, find_peak_element_binary_search) {
    // single element
    vector<int> v1 = {1};
    EXPECT_TRUE(isPeak(v1, FindPeakElement::findPeakElementBinarySearch(v1)));

    // two elements ascending
    vector<int> v2 = {1, 2};
    EXPECT_TRUE(isPeak(v2, FindPeakElement::findPeakElementBinarySearch(v2)));

    // two elements descending
    vector<int> v3 = {2, 1};
    EXPECT_TRUE(isPeak(v3, FindPeakElement::findPeakElementBinarySearch(v3)));

    // [1,2,3,1]
    vector<int> v4 = {1, 2, 3, 1};
    EXPECT_TRUE(isPeak(v4, FindPeakElement::findPeakElementBinarySearch(v4)));

    // [1,2,1,3,5,6,4]
    vector<int> v5 = {1, 2, 1, 3, 5, 6, 4};
    EXPECT_TRUE(isPeak(v5, FindPeakElement::findPeakElementBinarySearch(v5)));

    // ascending array — peak must be last element
    vector<int> v6 = {1, 2, 3, 4, 5};
    EXPECT_TRUE(isPeak(v6, FindPeakElement::findPeakElementBinarySearch(v6)));

    // descending array — peak must be first element
    vector<int> v7 = {5, 4, 3, 2, 1};
    EXPECT_TRUE(isPeak(v7, FindPeakElement::findPeakElementBinarySearch(v7)));

    // multiple peaks
    vector<int> v8 = {1, 3, 2, 4, 1};
    EXPECT_TRUE(isPeak(v8, FindPeakElement::findPeakElementBinarySearch(v8)));
}

TEST(array, find_peak_element_linear) {
    // single element
    vector<int> v1 = {1};
    EXPECT_TRUE(isPeak(v1, FindPeakElement::findPeakElementLinear(v1)));

    // two elements ascending
    vector<int> v2 = {1, 2};
    EXPECT_TRUE(isPeak(v2, FindPeakElement::findPeakElementLinear(v2)));

    // two elements descending
    vector<int> v3 = {2, 1};
    EXPECT_TRUE(isPeak(v3, FindPeakElement::findPeakElementLinear(v3)));

    // [1,2,3,1]
    vector<int> v4 = {1, 2, 3, 1};
    EXPECT_TRUE(isPeak(v4, FindPeakElement::findPeakElementLinear(v4)));

    // [1,2,1,3,5,6,4]
    vector<int> v5 = {1, 2, 1, 3, 5, 6, 4};
    EXPECT_TRUE(isPeak(v5, FindPeakElement::findPeakElementLinear(v5)));

    // ascending array — peak must be last element
    vector<int> v6 = {1, 2, 3, 4, 5};
    EXPECT_TRUE(isPeak(v6, FindPeakElement::findPeakElementLinear(v6)));

    // descending array — peak must be first element
    vector<int> v7 = {5, 4, 3, 2, 1};
    EXPECT_TRUE(isPeak(v7, FindPeakElement::findPeakElementLinear(v7)));

    // multiple peaks
    vector<int> v8 = {1, 3, 2, 4, 1};
    EXPECT_TRUE(isPeak(v8, FindPeakElement::findPeakElementLinear(v8)));
}
