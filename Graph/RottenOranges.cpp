#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rottenOranges(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size(); //number of columns

    queue<pair<pair<int,int>,int>> q; //storing {{row,col},time}
    vector<vector<int>> visited(n,vector<int>(m,0)); //visited arrray
    //travel along the grid and get all rotten oranges
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});//initially rotten tomatoes,time = 0.
                visited[i][j] = 2; //mark them rotten
            }
            else
            {
                visited[i][j] =0; //empty cell
            }
        }
    }
    int time = 0;
    while(!q.empty())
    {
        int r = q.front().first.first;//row number
        int c = q.front().first.second;//col number
        int t = q.front().second;//time
        q.pop();
        time = max(time,t);

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int i=0;i<4;i++) //go through all 4 neighbors
        {
            int nRow = r+delRow[i];
            int nCol = c+delCol[i];
            //check validity of neighbors-->
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]!=2 && grid[nRow][nCol]==1)
            {
                q.push({{nRow,nCol},t+1});//time increases
                visited[nRow][nCol] = 2;
            }
        }
    }

    //after BFS traversal, check if any fresh orange is left
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]!=2 && grid[i][j]==1)
            {
                return -1;
            }
        }
    }
    return time;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout<<rottenOranges(grid)<<endl;
    return 0;
}
