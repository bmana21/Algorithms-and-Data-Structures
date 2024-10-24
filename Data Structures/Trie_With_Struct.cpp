struct TrieNode {
    TrieNode *next[26]{};  // We Only Have Lower Case Latin Letter For This Implementation {a..z}
    int data;  // Can Be Any Type

    TrieNode() {
        for (auto & i : next) {
            i = nullptr;
        }
        data = -1;
    }

    // Add String In The Trie With Value d (example: trie.add("HelloWorld", 12); )
    void add(const string &s, int d, int pos = 0) {
        if (pos == s.size()) {
            data = d;
            return;
        }
        int p = s[pos] - 'a';
        if (next[p] == nullptr)
            next[p] = new TrieNode();

        next[p]->add(s, d, pos + 1);

    }

    // Get String Value That Is Added In Trie (-1 If It Is Not Added).
    // (example: int data = trie.get("HelloWorld"); )
    int get(const string &s, int pos = 0) {
        if (s.size() == pos) {
            return data;
        }
        int p = s[pos] - 'a';
        if (next[p] == nullptr)
            return -1;
        else return next[p]->get(s, pos + 1);
    }

};
