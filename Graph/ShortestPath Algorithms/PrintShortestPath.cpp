#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> shortestPath(int n, vector<pair<int,int>>adj[]) //1 based array, source always 1
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq; //min-heap based pq
    vector<int>dist(n+1,1e9);
    vector<int>memo(n+1);
    pq.push({0,1});

    dist[1] = 0; //1 is the source,whose distance from itself=1
    for(int i=1;i<=n;i++)
    {
        memo[i] = i;
    }

    while(!pq.empty())
    {
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();

        for(auto x:adj[node])//traversing through all the adjacent nodes
        {
            int adjNode = x.first;
            int adjDis = x.second;

            if((dis + adjDis)< dist[adjNode])
            {
                dist[adjNode] = dis+adjDis;
                pq.push({dis+adjDis,adjNode});
                memo[adjNode] = node; //put parent of the adjacent node in required index for tracking path from  where it came from
            }
        }
    }
    if(dist[n]==1e9) //unable to reach destination
    {
        return {-1};
    }
    vector<int>path;
    //finding the path-->
    int nd = n;

    while(memo[nd]!=nd)//if its not source node. Basically we are backtracking through the path
    {
        path.push_back(nd);
        nd = memo[nd]; //node is updated from where it came(parent)
    }
    path.push_back(1);//source node 1 added at the end
    reverse(path.begin(),path.end()); //reverse the vector to get the path from source to destination

return path;
}
int main() //main() is built using A.I
{
     int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); //remove if graph is directed
    }

    vector<int> ans = shortestPath(n, adj);

    if(ans.size()==1 && ans[0]==-1)
    {
        cout << "No Path Exists\n";
    }
    else
    {
        cout << "Shortest Path: ";
        for(int x: ans) cout << x << " ";
        cout << "\n";
    }
}
