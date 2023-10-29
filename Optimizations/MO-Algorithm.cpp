// Structure to represent a query
struct Query {
    int left;
    int right;
    int index;
};

// Function to compare two queries based on their blocks and right values
bool compareQueries(const Query &q1, const Query &q2) {
    int blockSize = sqrt(q1.right);
    if (q1.left / blockSize != q2.left / blockSize) {
        return q1.left < q2.left;
    }
    return q1.right < q2.right;
}

// Function to process a query
void processQuery(int queryIndex) {
    // TODO: Implement the processing logic for the query
}

// Function to solve the queries using Mo's algorithm
void solveQueries(vector <Query> &queries, vector<int> &arr) {
    sort(queries.begin(), queries.end(), compareQueries);

    int currentLeft = 0;
    int currentRight = -1;

    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i].left;
        int right = queries[i].right;
        int index = queries[i].index;

        while (currentLeft > left) {
            currentLeft--;
            // TODO: Add logic to process the element at currentLeft
        }
        while (currentRight < right) {
            currentRight++;
            // TODO: Add logic to process the element at currentRight
        }
        while (currentLeft < left) {
            // TODO: Add logic to remove the element at currentLeft
            currentLeft++;
        }
        while (currentRight > right) {
            // TODO: Add logic to remove the element at currentRight
            currentRight--;
        }

        processQuery(index);
    }
}

int main() {
    int n; // Size of the array
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q; // Number of queries
    cin >> q;

    vector <Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].index = i;
    }

    solveQueries(queries, arr);

    return 0;
}