#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;  // szomszédsági lista, párokat tárol (szomszéd, élindex)
vector<int> degree;      // az egyes csomópontok fokszámának tárolására
vector<int> path;        // tárolja az Euler-kört
vector<bool> used;       // jelzi, hogy élt használnak-e

void findEulerianCircuit(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();

        // Ha ennek a csúcsnak nincs több meg nem látogatott éle
        if (adj[u].empty()) {
            path.push_back(u);
            st.pop();
        } else {
            // Meg nem látogatott él keresése
            auto [v, edgeIdx] = adj[u].back();
            adj[u].pop_back();
            if (!used[edgeIdx]) {
                used[edgeIdx] = true;  // Meglátogatottként való megjelölésre
                st.push(v);
            }
        }
    }
}

void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    for (auto [v, _] : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited);
        }
    }
}

bool isConnected() {
    vector<bool> visited(n + 1, false);

    // Az első éllel rendelkező csomópont megkeresése
    int start = -1;
    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }

    // Ha nincsenek élek, akkor triviálisan Euler-féle
    if (start == -1) return true;

    // Hajtsa végre a DFS-t erről a csomópontról
    dfs(start, visited);

    // Ellenőrizzük, hogy minden éllel rendelkező csomópont meg van-e látogatva
    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty() && !visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    degree.resize(n + 1, 0);
    used.resize(m, false);

    // Olvassa be az éleket, és készítse el a szomszédsági listát
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        degree[a]++;
        degree[b]++;
    }

    // Ellenőrizze, hogy a gráf tartalmazhat-e Euler-kört
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Ellenőrizze, hogy a gráf csatlakoztatva van-e
    if (!isConnected()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Keresse meg az Euler-kört az 1. csomóponttól kezdve (postahivatal)
    findEulerianCircuit(1);

    // Ellenőrizze, hogy minden élt használt-e
    if (path.size() == m + 1) {
        reverse(path.begin(), path.end());
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}