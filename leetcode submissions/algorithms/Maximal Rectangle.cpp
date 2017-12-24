class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int maxi=INT_MIN;
        vector<int> arr(matrix[0].size(),0);
        //for(int k : arr)
         //   cout<<k<<' ';
       // cout<<endl;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               // cout<<matrix[i][j];
                if(matrix[i][j]=='0')
                    arr[j]=0;
                else
                    arr[j]+=matrix[i][j]-'0';
            }
            //for(int k : arr)
              //  cout<<k<<' ';
            //cout<<endl;
            //int x=largestRectangleArea(arr);
           // cout<<x<<endl;
         maxi=max(maxi,largestRectangleArea(arr));   
        }
      return maxi ; 
    }
         int largestRectangleArea(vector<int> arr) {
            if(arr.size()==0)
                return 0;
            if(arr.size()==1)
                return arr[0];
            int n=arr.size();
            int tp=0,area=0,maxarea=INT_MIN,i=0;
            stack<int> s;
            while(i<n)
            {
            if(s.empty() || arr[s.top()]<=arr[i])
                s.push(i++);
            else
            {
                tp=s.top();
                s.pop();
                area= arr[tp]*(s.empty()?i:(i-s.top()-1));
                maxarea=max(maxarea,area);
            }
            }
            while(!s.empty())
            {
                tp=s.top();
                s.pop();
                area= arr[tp]*(s.empty()?i:(i-s.top()-1));
                maxarea=max(maxarea,area);
            }
        return maxarea;
     }    
    
};