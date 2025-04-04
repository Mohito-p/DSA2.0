#include<bits/stdc++.h>
using namespace std;
bool bfsCycleCheck(int src,vector<vector<int>>&graph,vector<int> &visited){
     visited[src]=1;
     queue<pair<int,int>>q;
     q.push({src,-1});
     while(!q.empty()){
         int x=q.front().first;
         int y=q.front().second;
         q.pop();
         for(auto node:graph[x]){
             if(!visited[node]){
                visited[node]=1;
                q.push({node,x});
             }
             else if(y!=node){
                return true;
             }
         }
     }
     return false;
}
bool dfsCycleCheck(int node,int parent,vector<int>&vis,vector<vector<int>>&graph){
     vis[node]=1;
     for(auto node:graph[node]){
        if(!visited[node]){
            if(dfsCycleCheck(node, parent, vis, graph)==true) return true;
        }
        else if(parent!=node){
            return true;
        }
        return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>>graph(n+1);
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n + 1, 0);
    bool hasCycle = false;    
    for (int i = 0; i <= n; i++) {
        if (!visited[i]) {
            if (bfsCycleCheck(i, graph, visited)) {
                hasCycle = true;
                break;
            }
        }
    }    
    if(hasCycle){
        return "Yes";
    }
    return "No";
}