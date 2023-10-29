
int knapsackOptimized(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        bitset<5001> filled = dp;
        for (int j = weights[i]; j <= capacity; j++) {
            int newValue = dp[j - weights[i]] + values[i];
            if (newValue > dp[j] && !filled[j]) {
                dp[j] = newValue;
                filled[j] = true;
            }
        }
    }

    return dp[capacity];
}
