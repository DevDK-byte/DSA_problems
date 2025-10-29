#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    //array of vectors
    vector<int> adj[n+1];//TAKE VECTOR AS THE LIST and initially no vertices in list
    for(int i=0;i<m;i++) //storing edges upto m
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); //we store the nodes which are adjacent
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
    for(auto x:adj[i])
    {
        cout<<x<<"->";
    }
    cout<<NULL<<endl;
    cout<<endl;
    }
    return 0;
}
