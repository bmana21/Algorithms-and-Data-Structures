const int N = 2e5 + 1;
const int lg = 23; // This should be approximately equal to log2(N)

int dp[N][lg];
int tin[N], tout[N];
bool used[N];
int timer = 0;

std::vector<int> g[N];

void DFS(int v, int par) {
    used[v] = true;
    dp[v][0] = par;
    for (int k = 1; k < lg; k++)
        dp[v][k] = dp[dp[v][k - 1]][k - 1];
    tin[v] = timer++;
    for (int to: g[v]) {
        if (!used[to])
            DFS(to, v);
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
