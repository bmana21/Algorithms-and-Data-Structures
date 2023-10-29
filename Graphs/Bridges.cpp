const int N = 2e5 + 1;

int t_low[N], t_in[N], used[N], timer;
map<pair<int, int>, bool> is_bridge;
vector<int> g[N];

void DFS(int v, int c) {
    used[v] = 1;
    t_low[v] = timer;
    t_in[v] = timer;
    timer++;
    for (int to: g[v]) {
        if (used[to] && c != to)
            t_low[v] = std::min(t_low[v], t_in[to]);
        else if (!used[to]) {
            DFS(to, v);
            t_low[v] = std::min(t_low[v], t_low[to]);
            if (t_in[v] < t_low[to]) {
                is_bridge[{v, to}] = true;
                is_bridge[{to, v}] = true;
            }
        }
    }
}