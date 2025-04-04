//shortest path bfs

#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
vector<int> visited;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void bfs(int src,vector<int> &dist) {
    queue<int> q;
    visited.clear();
    visited.resize(v, -1);
    dist.resize(v, INT_MAX);
    dist.push(src);
    visited[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        dist.push_back(curr);
        for (auto neighbour : graph[curr]) {
            if (!visited[neighbour]) { // Check if neighbour is unvisited
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
}

int main() {
    cin >> v;
    graph.resize(v); // Resize the graph

    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    int x, y;
    cin >> x >> y;

    vector<int> dist;
    bfs(x,dist);

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
