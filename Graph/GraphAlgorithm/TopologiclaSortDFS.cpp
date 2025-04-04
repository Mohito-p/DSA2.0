class Solution
{
public:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto child : adj[node])
        {
            if (!vis[child])
                dfs(child, vis, st,adj);
        }
        st.push(node);
    }
    vector<int> topoSort(int v, vector<vector<int>> &adj)
    {
        vector<int> vis(v, 0);
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st,adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
}