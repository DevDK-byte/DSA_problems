#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSortBfs(int n, vector<int>adj[])
{
    vector<int>indegree(n,0);
    queue<int>q;

    for(int i=0;i<n;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++; //for all adjacent nodes, there will be one incoming edge(in degree)
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0) //there will always be one node with in-degree zero(edge case)
        {
            q.push(i);
        }
    }
    vector<int>answer;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        answer.push_back(node);
        //now node is already in toposort. so we remove it's link and decrement ind-degree of its adjacent nodes-->

        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    return answer;
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
    vector<int>ans = topologicalSortBfs(n,adj);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
