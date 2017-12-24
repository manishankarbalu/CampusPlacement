class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {         
        
        vector<vector<int>> v(n,vector<int>(n));
        if(n==0)
            return v;
        int rowbeg=0,rowend=n-1,colbeg=0,colend=n-1,k=1;
        while(rowbeg<=rowend && colbeg<=colend )
        {
            for(int i=colbeg;i<=colend;i++)
                {v[rowbeg][i]=k;k++;}
            rowbeg++;
            for(int i=rowbeg;i<=rowend;i++)
                {v[i][colend]=k;k++;}
            colend--;
            if(rowbeg<=rowend && colbeg<=colend)
            {
                   for(int i=colend;i>=colbeg;i--)
                        {v[rowend][i]=k;k++;}
                    rowend--;
                for(int i=rowend;i>=rowbeg;i--)
                        {v[i][colbeg]=k;k++;}
                    colbeg++;
            }  
        }
        return v;      
    }
};