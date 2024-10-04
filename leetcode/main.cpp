#include <iostream>
#include <vector>
#include "src/util/bisect.hpp"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    vector<int> nums{0, 1, 2, 4, 5};
    cout << "binary search 2, index: " << bisect(nums, 2) << endl;
    int notFound = bisect(nums, 3), insert = ~notFound;
    cout << "binary search 3, index: " << notFound << endl;
    cout << "negating index " << notFound << " gives " << insert << endl;
    nums.insert(nums.begin() + insert, 3);
    cout << "after insert nums[" << insert << "] is " << nums[insert] << endl;
    cout << "nums size is " << nums.size() << endl;
    return 0;
}
