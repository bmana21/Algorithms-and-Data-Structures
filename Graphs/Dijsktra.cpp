const int N = 2e5 + 1;

int n, dis[N], way[N];

vector <pair<int, int>> g[N];
set <pair<int, int>> s;

vector<int> ans;

void init() {
    s.clear();
    for (int k = 1; k < n; k++)
        dis[k] = INT_MAX;
}

bool solve() {
    init();
    dis[1] = 0;
    s.insert({0, 1});

    while (!s.empty()) {
        // Extract the vertex with the minimum distance
        std::pair<int, int> v = *s.begin();
        s.erase(s.begin());

        // Traverse the neighbors of the current vertex
        for (const auto &edge: g[v.second]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // Update the distance if a shorter path is found
            if (dis[neighbor] > v.first + weight) {
                way[neighbor] = v.second;
                dis[neighbor] = v.first + weight;
                s.insert({dis[neighbor], neighbor});
            }
        }

        // Exit the loop if the destination vertex is reached
        if (v.second == n) {
            break;
        }
    }

    // Path was not found
    if (way[n] == 0) {
        return false;
    }

    // Reconstruct the shortest path
    way[1] = 0;
    int current = n;
    while (current != 0) {
        ans.push_back(current);
        current = way[current];
    }
    return true;
}