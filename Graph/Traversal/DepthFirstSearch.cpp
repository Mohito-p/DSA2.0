//AnyPATH
#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
vector<int>visited;
int v;
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
bool dfs(int curr, int dest){
    if(curr == dest) return true;
    visited[curr]=1;
    for(auto neighbour:graph[curr]){
        if(visited[neighbour]!=1){
            bool result=dfs(neighbour,dest);
            if(result) return true;
        }
    }
    return false;
}

bool anyPath(int src,int dest){
    return dfs(src,dest);
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    visited.clear();
    visited.resize(v,-1);
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<endl;

    return 0;
}