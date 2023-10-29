int largestfactor(int x) {
    for (int f = 2; f * f <= x; f++) {
        if (x % f == 0) {
            int f2 = x / f;
            return max(f, f2);
        }
    }
    return 1;
}
