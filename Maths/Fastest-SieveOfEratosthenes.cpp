const int N = 102000000;

int Size = 1, pref[N], zm[N];

int num_size(int x) {
    return 32 - __builtin_clz(x);
}

void push(int a) {
    pref[Size] = pref[Size - 1] + __builtin_popcount(a);
    zm[Size] = zm[Size - 1] + num_size(a);
}

int ip[N + 1], pr[N + 1]; // ip[p] == 0 if p is prime number

void SieveOfEratosthenes() {
    for (int p = 2; p <= N; p++) {
        if (ip[p] == 0) {
            ip[p] = p;
            pr[Size] = p;
            push(p);
            Size++;
        }
        for (int k = 1; k < Size && pr[k] <= ip[p] && p * pr[k] <= N; k++) {
            ip[p * pr[k]] = pr[k];
        }
    }
}

int main() {
    SieveOfEratosthenes();
    return 0;
}