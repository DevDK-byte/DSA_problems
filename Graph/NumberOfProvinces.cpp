#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis)
{
    vis[node] = 1;
    for(auto x: adjList[node])
    {
        if(!vis[x])
        {
            dfs(x,adjList,vis);
        }
    }
}
int numberOfProvinces(vector<vector<int>>adj, int v)
{
    vector<vector<int>> adjList(v); //adjacency list

    //convert adjacency matrix to adjacency list-->
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v;j++)
        {
            if(adj[i][j]==1 && i!=j) // if j is a neighbor of i and no self loop of a node
                adjList[i].push_back(j);
            }
        }
    }
    vector<int> vis(v,0);
    int count = 0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i,adjList,vis);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> adj = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    int v = 3;
    cout << numberOfProvinces(adj, v); // Output: 2
}
