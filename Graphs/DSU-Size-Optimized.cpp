const int N = 2e5 + 1;

vector<int> par(N);
vector<int> sz(N);

void make_sets(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v) {
    if (par[v] == v) {
        return v;
    } else {
        return par[v] = find_set(par[v]);
    }
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}