class Solution {
public:
    int coinChange(vector<int>& coins, int v) {
     
        if(v==0)
            return 0;
        int MAX=v+1;
        vector<int> value(v+1,MAX);
       // for (int i : value)
         //   cout<<i<<' ';
        value[0]=0;
        int n=coins.size();
        
        for(int i=1;i<=v;i++)
        {
            //int sub=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                    value[i]=min(value[i],value[i-coins[j]]+1);
            }
            //value[i]=(sub!=INT_MAX)?sub+1:0;
        }
        //for (int i : value)
          //  cout<<i<<' ';
        return (value[v]>v)?-1:value[v];
    }
};