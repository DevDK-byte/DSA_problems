#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool bipartiteGraph(int n,vector<int>adj[])
{
    queue<int>q;
    vector<int>color(n+1,-1); //1 based indexing

    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            q.push(i);
            color[i] = 0;
        }
    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(auto it: adj[current])
        {
            if(color[it]==-1) //if any adjacent node is not colored
            {
                color[it] = !color[current]; //putting opposite color of current node to adjacent node
                q.push(it);
            }
            else if(color[it]==color[current]) //if same color not bipartite
            {
                return false;
            }
        }
    }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bipartiteGraph(n,adj)==true)
    {
        cout<<"Bipartite"<<endl;
    }
    else
        cout<<"not bipartite";

    return 0;
}
