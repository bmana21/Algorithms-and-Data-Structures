const int N = 2e5 + 1;

int t[4 * N], lazy[4 * N], a[N];


void build(int v) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        t[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
}


void update(int v, int tl, int tr, int l, int r, int new_value) {
    if (tl == l && tr == r)
        t[v] += new_value, lazy[v] += new_value;
    else {
        if (l > r)return;
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(tm, r), new_value);
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, new_value);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

}

int get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return LONG_LONG_MAX;
    if (tl == l && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(get_min(v * 2, tl, tm, l, min(tm, r)), get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
