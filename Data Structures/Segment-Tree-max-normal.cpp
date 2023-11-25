const int N = 2e5 + 1;

int t[4 * N];
int a[N];

void build(int v, int i, int j) {
    if (i == j) {
        t[v] = a[i];
        return;
    }
    int mid = (i + j) / 2;
    build(v * 2, i, mid);
    build(v * 2 + 1, mid + 1, j);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int i, int j, int pos, int val) {
    if (i == j) {
        t[v] = val;
        return;
    }
    int mid = (i + j) / 2;
    if (pos <= mid)
        update(v * 2, i, mid, pos, val);
    else
        update(v * 2 + 1, mid + 1, j, pos, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int i, int j, int l, int r) {
    if (l > r)
        return 0;
    if (i == l && j == r)
        return t[v];
    int mid = (i + j) / 2;
    return max(get(v * 2, i, mid, l, min(mid, r)),
               get(v * 2 + 1, mid + 1, j, max(mid + 1, l), r));
}
