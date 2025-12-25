#include<iostream>
#include<climits>
#include<vector>
#include<set>
using namespace std;

vector<int> dijkstraSet(int v, vector<vector<int>>adj[],int source)
{
    set<pair<int,int>>st;//{distance,node}
    vector<int>dist(v,INT_MAX);
    dist[source] = 0;  // source distance initialized
    st.insert({0,source});

    while(!st.empty())
    {
        //it here picks the first smallest element only
        auto it = *(st.begin()); //iterator pointing to value(*) of set's first element
        int node = it.second;
        int distance = it.first;
        st.erase(st.begin());

        for(auto edge: adj[node])
        {
            int adjacent_node = edge[0];
            int edgeDistance = edge[1];

            if((distance + edgeDistance) < dist[adjacent_node])
            {
                if(dist[adjacent_node] != INT_MAX) //erase if another distance existed bigger than new smaller distance and is not infinity
                {
                    st.erase({dist[adjacent_node],adjacent_node});
                }
                dist[adjacent_node] = distance + edgeDistance; //update prev distance
                st.insert({dist[adjacent_node],adjacent_node});
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

    // undirected weighted graph
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> ans = dijkstraSet(v, adj, source);

    for(int i = 0; i < v; i++)
        cout << "Distance to " << i << " = " << ans[i] << endl;
}
