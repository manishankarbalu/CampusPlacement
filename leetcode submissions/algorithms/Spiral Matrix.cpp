class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        vector<int> v;
       
         if(m.size()==0 || m[0].size()==0)
            return v;
        int rowbeg=0,rowend=m.size()-1, colbeg=0,colend=m[0].size()-1;
       
        while(rowbeg<=rowend && colbeg<=colend)
        {
            for(int i=colbeg;i<=colend;i++)
            {
                v.push_back(m[rowbeg][i]);
            }
            rowbeg++;
            for(int i=rowbeg;i<=rowend;i++)
            {
                v.push_back(m[i][colend]);
            }
            colend--;
            if(rowbeg<=rowend && colbeg<=colend)
            {
                for(int i=colend;i>=colbeg;i--)
                {
                    v.push_back(m[rowend][i]);
                }
               rowend--;
            
                for(int i=rowend;i>=rowbeg;i--)
                {
                    v.push_back(m[i][colbeg]);
                }
             colbeg++;
            }  
        }
        return v;
    }
};