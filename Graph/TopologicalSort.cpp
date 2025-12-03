#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int>& vis, stack<int>&s,vector<int>adj[])
{
    vis[node] = 1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(int n, vector<int>adj[])
{
    stack<int>s;
    vector<int>vis(n,0);//0 based indexing

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,s,adj);
        }
    }
    vector<int>answer;
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
return answer;
}
int main()
{
    int n,m;
    cin>>n>>m;
    //for directed graph--> 0-based indexing
    vector<int>adj[n];//for 0 based indexing keep size n; for 1 based, keep size (n+1)
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans = topologicalSort(n,adj);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

