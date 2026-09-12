class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };
    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.ids < b.ids;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<int, 4>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // prev[i] = number of intervals before i
        // whose ending time < a[i].start
        vector<int> prev(n);
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (a[mid][1] < a[i][0])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            prev[i] = lo;
        }

        // dp[i][k] = best answer using first i intervals
        // with at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int i = 1; i <= n; i++) {
            // Don't take current interval
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }
            // Take current interval
            for (int k = 1; k <= 4; k++) {
                State candidate = dp[prev[i - 1]][k - 1];
                candidate.score += a[i - 1][2];
                candidate.ids.push_back(a[i - 1][3]);
                // Keep IDs sorted because final comparison
                // is lexicographical by original indices
                sort(candidate.ids.begin(), candidate.ids.end());
                if (better(candidate, dp[i][k])) {
                    dp[i][k] = candidate;
                }
            }
        }
        // Best answer among at most 4 intervals
        State ans = dp[n][1];
        for (int k = 2; k <= 4; k++) {
            if (better(dp[n][k], ans))
                ans = dp[n][k];
        }
        return ans.ids;
    }
};