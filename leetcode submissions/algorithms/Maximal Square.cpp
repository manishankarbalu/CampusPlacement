class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size(); int num=0;
        if(n==1)
            return matrix[0][0]-'0';
        vector<vector<int>> arr(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            {arr[i][0]=matrix[i][0]-'0';
            num=max(num,arr[i][0]);}
        for(int i=0;i<n;i++)
            {arr[0][i]=matrix[0][i]-'0';
            num=max(num,arr[0][i]);}
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    arr[i][j]=min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]))+1;
                num=max(num,arr[i][j]);
            }
        }
        return num*num;
    }
};