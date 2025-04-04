class Solution{
    private:
    vector<int> topsBFS(int v,vector<vector<int>> graph){
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto neighbour:graph[i]){
                indegree[neighbour]++;
            }
        }
        queue<int>qu;
        unordered_set<int>vis;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                qu.push(i);
                vis.insert(i);
            }
        }
        vector<int>topo;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            topo.push_back(node);
            for(auto neighbour: graph[node]){
                if(!vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        qu.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
        return topo;
    }
    public:
    string findOrder(vector<string> &word,int n,int k){
        vector<vector<int>> graph(n);
        for(int i=0;i<n-1;i++){
            string s1=word[i];
            string s2=word[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]) {
                    graph[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> order=topsBFS(k,graph);
        string ans="";
        for(auto it:order){
            ans+=char(it+'a');
        }
        return ans;
    }
};