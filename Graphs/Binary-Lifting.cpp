const int N = 2e5 + 1;
const int lg = 23; // This should be approximately equal to log2(N)

int dp[N][lg], tin[N], tout[N];
int timer = 0;

vector<int> g[N];

void DFS(int v, int par) {
    tin[v] = timer++;
    dp[v][0] = par;
    for (int k = 1; k < lg; k++)
        dp[v][k] = dp[dp[v][k - 1]][k - 1];
    for (int to : g[v]) {
        if (par != to) {
            DFS(to, v);
        }
    }
    tout[v] = timer++;
}

bool isAncestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (isAncestor(a, b))
        return a;
    if (isAncestor(b, a))
        return b;

    int t = a;
    for (int k = lg - 1; k >= 0; k--) {
        if (dp[t][k] != 0) {
            int to = dp[t][k];
            if (!isAncestor(to, b))
                t = to;
        }
    }
    return dp[t][0];
}

int lift(int v, int dist) {
    for (int k = lg - 1; k >= 0; k--) {
        if (dist >= (1 << k)) {
            v = dp[v][k];
            dist -= 1 << k;
        }
    }
    return v;
}
