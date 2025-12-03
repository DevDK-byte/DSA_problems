#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>adj[])
{
    //initially the node for which dfs is running will be by default path and normal visited
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node])
    {
        //if node not visited
        if(!vis[it])
        {
            if(dfs(it,vis,pathVis,adj)==true) //if finds a cycle in the same path(No need to check for further adjacent nodes)
            {
                return true;
            }
        }
        //if the node has been previously visited(But on same path only)-->
        else if(pathVis[it]) //if same path
        {
            return true;
        }
    }

    //before backtracking, pathvis[node] is unmarked!!!
    pathVis[node]=0;
    return false;
}
bool detectCycleDfs(int n, vector<int>adj[])
{
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    for(int i=0;i<n;i++)//for all components
    {
        if(!vis[i])
        {
            if(dfs(i,vis,pathVis,adj)==true)
                return true;
        }
    }
return false;
}

bool detectCycleBfs(int n, vector<int>adj[]) //applying Kahn's Algorithm
{
    vector<int>indegree(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int counter = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        counter++;

        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    if(counter==n)
        return false;

return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    //for directed graph--> 0-based indexing
    vector<int>adj[n];//for 0 based indexing keep size n; for 1 based, keep size (n+1)
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    /*if(detectCycleDfs(n,adj)==true)
        cout<<"yes has cycle"<<endl;
    else
        cout<<"no cycle";*/
        if(detectCycleBfs(n,adj)==true)
        {
            cout<<"Cycle detected"<<endl;
        }
        else
            cout<<"No cycle detected"<<endl;
    return 0;
}
