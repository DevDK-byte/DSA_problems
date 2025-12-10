#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
//using BFS under the hood
vector<int> dijkstra(int v, vector<vector<int>> adj[], int source) //taken a list of vectors instead of pair
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //pq having pair>distance,node>
    vector<int>dist(v,INT_MAX); //distance array
    dist[source] = 0; //source node distance from itself always zero
    pq.push({0,source});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        //traveling for adjacent nodes-->
        for(auto it: adj[node])
        {
            int edgeWeight = it[1]; //as adj list stores node and its weight, weight is at second index of 'it'
            int adj_node = it[0]; //node is at first index

            if((distance + edgeWeight) < dist[adj_node]) //if better distance found than prev distance for adjacent node
            {
                dist[adj_node] = distance + edgeWeight; //update previous distance
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    return dist;

}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // UNDIRECTED GRAPH
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist = dijkstra(v, adj, source);

    for(int i = 0; i < v; i++)
        cout << "Node " << i << " Distance = " << dist[i] << endl;
    return 0;
}
