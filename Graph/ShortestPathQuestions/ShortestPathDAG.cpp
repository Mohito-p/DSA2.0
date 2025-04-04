#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        for (auto child : adj[node]) {
            int v = child.first;
            if (!vis[v]) 
                dfs(v, vis, st, adj);
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];


        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;  
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX) {  
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) 
                dist[i] = -1;
        }

        return dist;
    }
};