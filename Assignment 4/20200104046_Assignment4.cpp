#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& cycle_nodes) {
    visited[src] = true;
    recStack[src] = true;

    for (auto i : adj[src]) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, cycle_nodes)) {
                cycle_nodes.push_back(i);
                return true;
            }
        }
        else if (recStack[i]) {
            cycle_nodes.push_back(i);
            return true;
        }
    }

    recStack[src] = false;
    return false;
}

vector<vector<int>> findCycles(vector<vector<int>>& adj, int n, int& cycle_count) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    vector<vector<int>> cycles;
    vector<int> cycle_nodes;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, adj, visited, recStack, cycle_nodes)) {
            cycle_nodes.push_back(i);
            cycles.push_back(cycle_nodes);
            cycle_nodes.clear();
            cycle_count++;
        }
    }

    return cycles;
}

int main() {
    cout << "Enter the number of nodes and edges:";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    cout << "Enter the graph: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int cycle_count = 0;
    vector<vector<int>> cycles = findCycles(adj, n, cycle_count);

    if (!cycles.empty()) {
        cout << "Deadlock Present. Deadlock Count: " << cycle_count << "\n";
        for (const vector<int>& cycle : cycles) {
            for (int node : cycle) {
                cout << node << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "No Deadlock present";
    }
}

/*
6 8

0 1
1 2
2 0
2 3
3 1
3 4
4 5
5 3
*/
