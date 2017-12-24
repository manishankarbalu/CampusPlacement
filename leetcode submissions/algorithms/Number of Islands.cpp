class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0)
            return 0;
        if(grid[0].size()==0)
            return 0;
        int n=grid.size(),m=grid[0].size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    find(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
      /*  for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
         cout<<grid[i][j]<<' ';
            }
            cout<<'\n';
        }*/
        
        return cnt;
    }
    void find(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        find(i+1,j,n,m,grid);
        find(i-1,j,n,m,grid);
        find(i,j+1,n,m,grid);
        find(i,j-1,n,m,grid);
    }
};