const int N = 2e5 + 1;

vector<int> par(N);

void make_sets(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
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
        par[b] = a;
    }
}
