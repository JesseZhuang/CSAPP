#ifndef LEETCODE_PROJECTEULER208_HPP
#define LEETCODE_PROJECTEULER208_HPP

// https://projecteuler.net/problem=208
// http://euler.stephan-brumme.com/208/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const auto Unknown = 0xFFFFFFFFFFFFFFFFull;

// logic is based on state (arc1, arc2, arc3, arc4, arc5) counts must be all equal and curArc==0
class Solution {
public:
    unsigned char numVisited[5] = {0, 0, 0, 0, 0};
    unsigned char maxPerArc = 0;
    unsigned char m;

    explicit Solution(unsigned char m) : m(m) {
        maxPerArc = m / 5;
    }

#define FAST
#ifdef  FAST
    std::vector<unsigned long long> cache;
#else
    std::unordered_map<unsigned int, unsigned long long> cache;
#endif

    unsigned long long journeys() {
        return helper(m);
    }

    unsigned long long helper(unsigned char arcsLeft, unsigned char currentArc = 0) {
        if (arcsLeft == 0) { // all arcs were used
            if (currentArc != 0) return 0;
            // expect that all arcs were visited equally often
            if (numVisited[0] != numVisited[1] ||
                numVisited[2] != numVisited[3] ||
                numVisited[0] != numVisited[2]) // no need to check visited[4]
                return 0;
            return 1;
        }

        // create a unique key, hashing
        const auto IdFactor = maxPerArc + 1;
        unsigned int id = currentArc;
        id *= IdFactor;
        id += numVisited[0];
        id *= IdFactor;
        id += numVisited[1];
        id *= IdFactor;
        id += numVisited[2];
        id *= IdFactor;
        id += numVisited[3];
        id *= IdFactor;
        id += numVisited[4];
        // memoize
#ifdef FAST
        if (cache.empty())
            cache.resize(5 * IdFactor * IdFactor * IdFactor * IdFactor * IdFactor, Unknown);
        if (cache[id] != Unknown)
            return cache[id];
#else
        auto lookup = cache.find(id);
        if (lookup != cache.end())
            return lookup->second;
#endif

        unsigned long long result = 0;

        // turn left if possible
        auto turnLeft = (currentArc + 1) % 5;
        if (numVisited[turnLeft] < maxPerArc) {
            numVisited[turnLeft]++;
            result += helper(arcsLeft - 1, turnLeft);
            numVisited[turnLeft]--; // backtrack
        }

        // turn right if possible
        auto turnRight = (currentArc + 4) % 5; // -1 mod 5 => 5-1 mod 5
        if (numVisited[turnRight] < maxPerArc) {
            numVisited[turnRight]++;
            result += helper(arcsLeft - 1, turnRight);
            numVisited[turnRight]--;
        }

        // save result
        cache[id] = result;
        return result;
    }

};

#endif //LEETCODE_PROJECTEULER208_HPP
