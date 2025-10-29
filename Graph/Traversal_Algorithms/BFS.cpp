#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsTraversal(int v, vector<int> adj[])//parameters-> v=number of nodes,adj[] = graph list
{
    vector<int>vis(v+1,0); //visited array to keep track of nodes already visited
    vis[0] = 1; //initially starting node is visited
    queue<int>result; //queue to store the traversed vertices
    result.push(0); //initially queue will have starting node(if any). 0 based graph
    vector<int>bfs; //a vector to store the traversal

    while(!result.empty())
    {
        int node = result.front();
        result.pop();
        bfs.push_back(node);
        //adj[] list is storing a vector node, and this node vector is storing all neighbor elements!
        for(auto it:adj[node])
        {
            if(!vis[it])//if any neighbor is not visited,mark it visited
            {
                vis[it] = 1;
                result.push(it);
            }
        }
    }
    return bfs;
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
    vector<int>ans = bfsTraversal(n,adj);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
