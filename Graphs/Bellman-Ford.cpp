const int N = 2e5 + 1;

struct Edge {
    int source;
    int destination;
    int weight;
};

vector<int> distances;

bool BellmanFord(vector<Edge>& edges, int n, int source) {
    distances.resize(0);
    distances.resize(n + 1, INT_MAX);
    distances[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < n - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            return false; // Path won't be found
        }
    }
    
    return true;
    
}