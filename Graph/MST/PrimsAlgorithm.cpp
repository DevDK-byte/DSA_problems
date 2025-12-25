#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int mstPrims(int v, vector<vector<int>>adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>vis(v,0);//initially mark all as 0(unvisited) (1 will mean visited)
    //{weight,node}..(if asked for finding mst.store like{weight,node,parent})
    pq.push({0,0});

    int sum=0;
    while(!pq.empty())
    {
        auto it = pq.top();
        int wt = it.first;
        int node = it.second;
        pq.pop();

        if(vis[node]==1) //if already visited, skip that node
        {
            continue;
        }
        //if not visited, put it into MST-->(only when adding to MST, mark that node as visited!)
        vis[node] = 1;
        sum += wt;
        //if asked to show mst, we would've stored {parent,node} in this line in a list

        for(auto x:adj[node])
        {
            int adjNode = x[0];
            int adjWt = x[1];

            if(!vis[adjNode])
            {
                pq.push({adjWt,adjNode});
            }
        }
    }
return sum;
}

int main()
{
     int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for(int i = 0; i < e; i++)
    {
        int u, vtx, wt;
        cin >> u >> vtx >> wt;

        // undirected graph
        adj[u].push_back({vtx, wt});
        adj[vtx].push_back({u, wt});
    }

    cout << mstPrims(v, adj);
    return 0;
}
