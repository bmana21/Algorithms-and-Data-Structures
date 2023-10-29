#define mod 1e9 + 7

const int N = 2e5 + 2;

int f[N]; // n! % mod (factorial of n % mod)

// Calculate (x^y) % mod
int pow(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }
    return res % mod;
}

int inverse(int n) {
    return pow(n, mod - 2);
}

// Calculate C(n, m) % mod, number of combinations % mod
int C(int n, int m) {
    if (m == 0)
        return 1;
    return (((f[n] * mi(f[m])) % mod) * (inverse(f[n - m]) % mod)) % mod;
}

// Calculate (x + y) % mod
int add(int x, int y) {
    return ((x % mod) + (y % mod)) % mod;
}

// Calculate (x - y) % mod
int sub(int x, int y) {
    return ad(x % mod, mod - y);
}

int main() {
    f[0] = 1;
    for (int k = 1; k < N; k++) {
        f[k] = (k * f[k - 1]) % mod;
    }

    return 0;
}