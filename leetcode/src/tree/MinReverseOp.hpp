#ifndef MINREVERSEOP_HPP
#define MINREVERSEOP_HPP

#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        vector<int> res(n, -1);
        res[p] = 0;
        vector<int> nn(n); // next neighbor
        for (int i = 0; i < n; i++) nn[i] = i + 2;
        for (int b: banned) res[b] = -2;
        vector<int> q;
        q.push_back(p);
        int depth = 0, step = k - 1;
        while (!q.empty()) {
            vector<int> nq;
            depth++;
            for (int cur: q) {
                int lo = max(0, cur - step);
                lo = 2 * lo + step - cur;
                int hi = min(n - 1, cur + step) - step;
                hi = 2 * hi + step - cur;
                int postHi = hi + 2, nei = lo;
                while (nei <= hi) {
                    int nnei = nn[nei];
                    nn[nei] = postHi;
                    if (res[nei] == -1) {
                        res[nei] = depth;
                        nq.push_back(nei);
                    }
                    nei = nnei;
                }
            }
            q = nq;
        }
        for (int b: banned) res[b] = -1;
        return res;
    }
};

class Solution1 {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        vector<int> res(n, -1);
        res[p] = 0;
        queue<int> q({p});
        unordered_set<int> ban(banned.begin(), banned.end());
        set<int> s[2];
        for (int i = 0; i < n; i++)
            if (i != p && !ban.contains(i)) s[i & 1].insert(i);
        while (!q.empty()) {
            int cur = q.front(), step = k - 1;
            q.pop();
            int lo = max(0, cur - step);
            lo = 2 * lo + step - cur;
            int hi = min(n - 1, cur + step) - step;
            hi = 2 * hi + step - cur;
            int id = lo % 2;
            // lower_bound:bisect_left, first not less
            auto b = s[id].lower_bound(lo), e = s[id].upper_bound(hi);
            for (auto it = b; it != e; ++it) {
                res[*it] = res[cur] + 1;
                q.push(*it);
            }
            s[id].erase(b, e);
        }
        return res;
    }
};


#endif //MINREVERSEOP_HPP
