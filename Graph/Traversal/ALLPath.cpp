//AnyPATH
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
vector<int> visited;
vector<vector<int>> result;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int dest, vector<int>& path) {
    if (curr == dest) {
        path.push_back(curr);
        result.push_back(path); // Corrected typo here
        path.pop_back();
        return;
    }

    visited[curr] = 1;
    path.push_back(curr);

    for (auto neighbour : graph[curr]) {
        if (visited[neighbour] == -1) {
            dfs(neighbour, dest, path);
        }
    }

    path.pop_back();
    visited[curr] = -1; // Reset visited status for backtracking
}

void allPath(int src, int dest) {
    vector<int> path;
    dfs(src, dest, path); // Removed unnecessary `return`
}

int main() {
    cin >> v;
    graph.resize(v); // Removed `list<int>` initialization
    int e;
    cin >> e;

    visited.resize(v, -1); // Initialize `visited` vector with -1

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    int x, y;
    cin >> x >> y;

    allPath(x, y);

    for (auto path : result) {
        for (auto el : path) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}
