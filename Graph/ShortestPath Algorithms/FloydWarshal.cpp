#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> floydWarshalAlgorithm(vector<vector<int>>& adj)//taking adjacency matrix
{
    int n = adj.size();
    //initialize the matrix-->
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                adj[i][j] = 0;
            }
            else if(adj[i][j]==-1)//if any node not reachable(in question -1 may be denoted)
            {
                adj[i][j] = 1e9; //mark that position infinite
            }
        }
    }
    //main algorithm logic-->
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][k]<1e9 && adj[k][j]<1e9){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);}
            }
        }
    }

    //return the resultant matrix-->(marking the not reachables to -1 again)
    for(int i=0;i<n;i++)
    {
        if(adj[i][i]<0)
        {
            cout<<"negative cycle detected"<<endl;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(adj[i][j]==1e9)//if any node not reachable(in question -1 may be denoted)
           {
                adj[i][j] = -1; //mark that position infinite
           }
        }
    }
return adj;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> adj[i][j];

    vector<vector<int>> result = floydWarshalAlgorithm(adj);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
