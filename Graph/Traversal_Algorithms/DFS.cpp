#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>& vis, vector<int>& dfsList)//finding dfs of each node
{
        vis[node] = 1;
        dfsList.push_back(node);
        //traverse all neighbours-->
        for(auto x:adj[node])
        {
            if(!vis[x])//if the neighbour not visited
            {
                dfs(x,adj,vis,dfsList);
            }
        }
}
vector<int> dfsTraversal(int v, vector<int>adj[])
{
    vector<int> vis(v,0);//0-based node starting
    vector<int>dfsList;//store the traversal
    int start = 3;//starting node
    dfs(start,adj,vis,dfsList);

return dfsList;
}
int main()
{
    int n,m;
    cin>>n>>m;
    //for undirected graph--> 0-based indexing
    vector<int>adj[n];//for 0 based indexing keep size n; for 1 based, keep size (n+1)
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans = dfsTraversal(n,adj);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
