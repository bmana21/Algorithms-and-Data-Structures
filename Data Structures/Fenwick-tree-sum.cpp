const int N = 2e5 + 2;
std::vector<int> fen(N);

long long get(long long i) {
    long long sum = 0;
    while (i >= 1) {
        sum += fen[i];
        i -= i & -i;
    }
    return sum;
}

void update(long long i, long long val) {
    while (i < N) {
        fen[i] += val;
        i += i & -i;
    }
}