vector<int> z_function(string str) {
    int n = str.length();
    vector<int> Z(n, 0);

    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            Z[i] = min(right - i + 1, Z[i - left]);
        }
        while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > right) {
            left = i;
            right = i + Z[i] - 1;
        }
    }

    return Z;
}