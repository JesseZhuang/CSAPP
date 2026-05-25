#ifndef LEETCODE_GASSTATION_HPP
#define LEETCODE_GASSTATION_HPP

#include <vector>

using namespace std;

// Solution 1: Greedy One-Pass - Time O(n), Space O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;    // O(1) track overall feasibility
        int tank = 0;                        // O(1) current tank level
        int start = 0;                       // O(1) candidate starting station

        for (int i = 0; i < n; ++i) {       // O(n) single pass through all stations
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If tank becomes negative, all stations from start to i cannot be the answer
            // because we know we can reach i from start, so if we start at any station
            // between start and i, we'll have less gas when reaching i
            if (tank < 0) {
                start = i + 1;              // try next station as new starting point
                tank = 0;                    // reset tank for new candidate
            }
        }

        // If total gas < total cost, no solution exists
        return totalGas >= totalCost ? start : -1;
    }
};

// Solution 2: Brute Force - Time O(n^2), Space O(1)
class Solution2 {
public:
    int canCompleteCircuitBrute(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int start = 0; start < n; ++start) {  // O(n) try each starting station
            int tank = 0;                           // O(1) current tank level
            int stationsVisited = 0;

            for (int i = start; stationsVisited < n; i = (i + 1) % n) {  // O(n) simulate circuit
                tank += gas[i] - cost[i];
                if (tank < 0) break;                // cannot proceed, try next start
                ++stationsVisited;
            }

            if (stationsVisited == n) return start; // completed full circuit
        }

        return -1;  // no valid starting station found
    }
};

#endif // LEETCODE_GASSTATION_HPP
