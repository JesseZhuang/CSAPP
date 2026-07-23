#ifndef ONLINE_STOCK_SPAN_HPP
#define ONLINE_STOCK_SPAN_HPP

#include <stack>
#include <vector>
#include <utility>

using namespace std;

// LeetCode 901 - Online Stock Span (Monotonic Stack)
// Time: O(1) amortized per call, Space: O(n)
class StockSpanner {
    stack<pair<int, int>> st; // (price, span)

public:
    StockSpanner() = default;

    int next(int price) {
        int span = 1;
        // Pop all elements with price <= current, accumulate their spans
        while (!st.empty() && st.top().first <= price) { // O(1) amortized
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

// LeetCode 901 - Online Stock Span (DP / Jump-back approach)
// Time: O(1) amortized per call, Space: O(n)
class StockSpannerDP {
    vector<int> prices;
    vector<int> spans;

public:
    StockSpannerDP() = default;

    int next(int price) {
        prices.push_back(price);
        int idx = prices.size() - 1;
        int span = 1;
        // Jump backwards using previously computed spans
        int j = idx - 1;
        while (j >= 0 && prices[j] <= price) { // O(1) amortized
            span += spans[j];
            j -= spans[j]; // jump back by span[j] positions
        }
        spans.push_back(span);
        return span;
    }
};

#endif //ONLINE_STOCK_SPAN_HPP
