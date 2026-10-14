#ifndef KTH_DISTINCT_STRING_HPP
#define KTH_DISTINCT_STRING_HPP

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> frequency;
        for (const std::string& value : arr) {
            ++frequency[value];
        }

        // The counting pass and the ordered scan each take O(n) expected time.
        for (const std::string& value : arr) {
            if (frequency[value] == 1 && --k == 0) {
                return value;
            }
        }

        // The frequency map stores up to n strings, so extra space is O(n).
        return "";
    }
};

#endif // KTH_DISTINCT_STRING_HPP
