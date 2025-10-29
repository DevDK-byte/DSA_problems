#include<iostream>
#include<vector>
using namespace std;

/* adjacency list-->
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //direction is from u---->v only. Just put v to u's List
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(auto x : adj[i])
        {
            cout<<x<<" -> ";
        }
        cout<<NULL<<endl;
        cout<<endl;
    }
    return 0;
} */
//adjacency matrix-->
int main()
{
    int n,m;
    cin>>n>>m;

    int adj[n+1][n+1] = {0};
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //direction from u to v (directed)
        adj[u][v] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
