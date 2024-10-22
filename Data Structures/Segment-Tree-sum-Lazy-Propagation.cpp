const int N = 2e5 + 1;

int arr[N], t[4 * N + 1], lazy[4 * N + 1];

void build(int v, int tl, int tr) {
    if (tl > tr)
        return;
    if (tl == tr) {
        t[v] = arr[tl];
        return;
    }

    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

void update(int v, int tl, int tr, int l, int r, int diff) {
    if (lazy[v] != 0) {
        t[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (tl > tr || tl > r || tr < l)
        return;
    if (tl >= l && tr <= r) {
        t[v] += (tr - tl + 1) * diff;

        if (tl != tr) {
            lazy[v * 2] += diff;
            lazy[v * 2 + 1] += diff;
        }
        return;
    }

    int mid = (tl + tr) / 2;
    update(v * 2, tl, mid, l, r, diff);
    update(v * 2 + 1, mid + 1, tr, l, r, diff);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (lazy[v] != 0) {
        t[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (tl > tr || tl > r || tr < l)
        return 0;
    if (tl >= l && tr <= r)
        return t[v];
    int mid = (tl + tr) / 2;
    return get(2 * v, tl, mid, l, r) +
           get(2 * v + 1, mid + 1, tr, l, r);
}
