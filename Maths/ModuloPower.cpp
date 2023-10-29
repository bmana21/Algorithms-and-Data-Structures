#define mod 1e9 + 7

int Pow(int x, int y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0) {
        int t = mypow(x, y / 2);
        return (t * t) % mod;
    } else {
        int t = mypow(x, y / 2);
        return (x * t * t) % mod;
    }
}
