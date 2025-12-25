#include<iostream>
#include<vector>
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
int main()
{
    DisjointSet ds(7);
    //connect the vertices according to question using union-->
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    //check here if 3 and 7 belongs to same component--> (no)
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    ds.unionByRank(3,7);
    //check again after connecting 3 with 7--> (yes)
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
