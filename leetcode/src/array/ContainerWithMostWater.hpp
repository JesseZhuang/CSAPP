#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class ContainerWithMostWater {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int res = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            res = max(res, area);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return res;
    }
};
