#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bellmanFord(int v, vector<vector<int>>& edge,int source)
{
    vector<int>dist(v,1e9);
    dist[source]= 0;
    //relax for (n-1) times-->
    for(int i=0;i<v-1;i++)
    {
        for(auto it: edge)
        {
            int node = it[0];
            int edges = it[1];
            int edgeWeight = it[2];

            if(dist[node]!=1e9 && (dist[node] + edgeWeight)< dist[edges])
            {
                dist[edges] = dist[node] + edgeWeight;
            }
        }
    }
    //nth relaxation to check if a graph has negative cycle-->
    for(auto x:edge)
    {
        int n = x[0];
        int m = x[1];
        int wt = x[2];

        if(dist[n]!=1e9 && (dist[n]+wt)<dist[m]) //distance still reducing at nth iteration
        {
            return {-1};
        }
    }
return dist;
}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges; //edgeList
    for(int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int source;
    cin >> source;

    vector<int> ans = bellmanFord(V, edges, source);

    if(ans[0] == -1)
    {
        cout << "Negative cycle detected\n";
    }
    else
    {
        for(int i = 0; i < V; i++)
            cout << "Dist from source to " << i << " = " << ans[i] << endl;
    }
}
