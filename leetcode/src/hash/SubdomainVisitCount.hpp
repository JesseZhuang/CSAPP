#pragma once
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// leet 811, hash map. O(nm) time, O(nm) space.
class SolutionSubdomainVisitCount {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> cnt;
        for (const string &cd : cpdomains) {
            int sp = cd.find(' ');
            int n = stoi(cd.substr(0, sp));
            string domain = cd.substr(sp + 1);
            cnt[domain] += n;
            for (int i = 0; i < (int)domain.size(); i++) {
                if (domain[i] == '.') cnt[domain.substr(i + 1)] += n;
            }
        }
        vector<string> res;
        for (auto &[d, c] : cnt) res.push_back(to_string(c) + " " + d);
        return res;
    }
};
