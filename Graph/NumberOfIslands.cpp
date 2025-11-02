#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

void dfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& grid)
{
    vis[row][col]  = 1; //initially unvisited
    queue<pair<int,int>> q;
    q.push({row,col});
    //bfs traversal(Dfs is also allowed)
    int n = grid.size(); //grid row size
    int m = grid[0].size();//grid col size
   /* while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();*/

        //traverse the neighbours and mark it-->
        //finding neighbour
        for(int nRow = -1; nRow<=1; nRow++)
        {
            for(int nCol = -1; nCol<=1; nCol++)
            {
                int neighbour_row = row + nRow;
                int neighbour_col = col + nCol;

                if(neighbour_row >= 0 && neighbour_row < n &&
                   neighbour_col >= 0 && neighbour_col < m &&
                   grid[neighbour_row][neighbour_col] == '1' &&
                   !vis[neighbour_row][neighbour_col])
                {
                    //vis[neighbour_row][neighbour_col] = 1;
                    //q.push({neighbour_row,neighbour_col});
                    //write only this recursive line for dfs traversal-->
                    dfs(neighbour_row, neighbour_col, vis, grid);
                }

            }
        }
    }


int numOfIslands(vector<vector<char>>& grid)
{
   int n = grid.size();
   int m = grid[0].size();
   int island_count = 0; //counts number of islands
   //creating a visited array and everything marked as unvisited
   vector<vector<int>> vis(n,vector<int>(m,0)); /*for each row,vector of m columns*/ //2d vector like matrix
   for(int i=0; i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(!vis[i][j] && grid[i][j]=='1')// if a place is not visited and is a land
           {
               island_count++;
               dfs(i,j,vis,grid);
           }
       }
   }
   return island_count;
}

int main()
{
     vector<vector<char>> grid = {
         {'1','1','0'},
         {'0','1','0'},
         {'1','0','1'},
         {'1','0','0'}};
     cout << numOfIslands(grid);
}
