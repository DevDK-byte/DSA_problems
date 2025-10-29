#include<iostream>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1]  = {0};
    for(int i=0;i<m;i++) //we store edges
    {
        int u,v;
        cin>>u>>v; //there will be edges between two nodes u and v;
        //mark the edges which are adjacent-->(for undirected graph)
        adj[u][v] = 1;
        adj[v][u] =1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
        cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
