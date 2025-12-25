#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class DisjointSet
{
    vector<int> rnk;
    vector<int> parent;
    vector<int> siize;

public:
    //initialize arrays with constructor-->
    DisjointSet(int n)
    {
        rnk.resize(n+1,0); //1-based indexing graph(resize the vector customly)
        parent.resize(n+1);
        siize.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            siize[i] = 1;
        }
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
        int findUltimateParent(int u)
        {
            if(u==parent[u]) //if node is parent itself,return parent (base case)
            {
                return u;
            }
            return parent[u] = findUltimateParent(parent[u]); //path compression
        }

        void unionByRank(int u,int v)
        {
            int ult_u = findUltimateParent(u);
            int ult_v = findUltimateParent(v);

            if(ult_u == ult_v) //if both belongs to same component
                return;
            if(rnk[ult_u]<rnk[ult_v])
            {
                parent[ult_u] = ult_v;
            }
            else if(rnk[ult_v]<rnk[ult_u])
            {
                parent[ult_v] = ult_u;
            }
            else //if both ranks same--> (connect anyone)
            {
                parent[ult_v] = ult_u;
                rnk[ult_u]++;
            }
        }
        void unionBySize(int u,int v)
        {
            int ultimate_u = findUltimateParent(u);
            int ultimate_v = findUltimateParent(v);

            if(ultimate_u == ultimate_v)
                return;
            if(siize[ultimate_u]<siize[ultimate_v])
            {
                parent[ultimate_u] = ultimate_v;
                siize[ultimate_v] += siize[ultimate_u];
            }
            else//if ult_v is smaller or both sizes are equal-->
            {
                parent[ultimate_v] = ultimate_u;
                siize[ultimate_u] += siize[ultimate_v];
            }
        }
};

int mstKruskals(int v,vector<vector<int>> adj[])
{
    vector<pair<int, pair<int,int>>>edges; //storing {weight,u,v}
    for(int i=0;i<v;i++) //zero-based indexing array
    {
        for(auto it: adj[i]) //go through adjacents of each node
        {
            int adjNode = it[0];
            int adjWeight = it[1];
            int node = i;

            edges.push_back({adjWeight, {node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    int mstWeight = 0;
    DisjointSet ds(v);

    for(auto it:edges)
    {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        //check if belongs to same component or not-->
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
        {
            mstWeight += weight;
            ds.unionBySize(u,v);
        } //else don't add weight and attach anyone
    }
return mstWeight;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for(int i = 0; i < E; i++) //zero based indexing graph
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        // undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int mstWeight = mstKruskals(V, adj);
    cout << "MST Weight = " << mstWeight << endl;

    return 0;
}

