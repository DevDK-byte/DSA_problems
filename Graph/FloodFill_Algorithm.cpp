#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col,vector<vector<int>>& answer,vector<vector<int>>& image,int newColor,int init_color)
{
    //initially color the entered pixel-->
    answer[row][col] = newColor;//during recursive calls, each required neighbor gets colored!
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    //traverse along all neighbors-->
    for(int i=0; i<4; i++) //each pixel has 4 neighbors
    {
             int n = image.size();
             int m = image[0].size(); //gives number of columns
             //find the neighbor row and neighbor column for each-->
             int nRow = row + delRow[i];
             int nCol = col + delCol[i];
             //check for validity of neighbors-->
             if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol] == init_color && answer[nRow][nCol]!=newColor/*if neighbor is not colored(not visited)*/)
             {
                 dfs(nRow,nCol,answer,image,newColor,init_color);
             }
         }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr,int sc, int newColor)
{
    int initial_color = image[sr][sc];
    vector<vector<int>> answer  = image;//copy all data from given image to another replica
    dfs(sr,sc,answer,image,newColor,initial_color);

return answer;
}
int main()
{
    vector<vector<int>> adj = {
        {1, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    vector<vector<int>> result = floodFill(adj,0,1,2);
    for(auto x:result)
    {
        for(auto y: x) //this means values of vector<int>x inside y variable stored
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
