#include<iostream>
#include<vector>
#include<stack>
#include<utility> //for pair
#include<climits>

using namespace std;

void dfsToposort(int i, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& s)
{
    vis[i] = 1;
    for(auto it: adj[i])
    {
        //node is in first of pair,weight in second-->
        int v = it.first;
        if(!vis[v])
        {
            dfsToposort(v, adj, vis, s);
        }
    }

    s.push(i);
}

vector<int> shortestPath(int nodes, int edges, vector<vector<int>>& edge)
{
    vector<pair<int,int>> adj[nodes];

    for(int i = 0; i < edges; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];
        adj[u].push_back({v, weight});
    }

    //doing toposort for all components-->
    stack<int> s;
    vector<int> vis(nodes, 0);

    for(int i = 0; i < nodes; i++)
    {
        if(!vis[i])
        {
            dfsToposort(i, adj, vis, s);
        }
    }

    //step-2 = Do the distance array part and mark all index infinity-->
    vector<int> dist(nodes, INT_MAX);
    dist[0] = 0; //source node always 0 for this problem(if source given, use dist[src] = 0)

    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if(dist[node] != INT_MAX)
        {
            for(auto it : adj[node])
            {
                int n = it.first;
                int wt = it.second;

                //relax the edges-->
                if((dist[node] + wt) < dist[n])
                {
                    dist[n] = dist[node] + wt; //update distance of prev node to new node
                }
            }
        }
    }
    return dist;
}

int main()
{
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> edge(edges, vector<int>(3));

    cout << "Enter edges in format: u v weight\n";
    for(int i = 0; i < edges; i++)
    {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    vector<int> result = shortestPath(nodes, edges, edge);

    cout << "\nShortest distance from node 0:\n";
    for(int i = 0; i < nodes; i++)
    {
        if(result[i] == INT_MAX)
            cout << "Node " << i << " -> INF\n";
        else
            cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}
