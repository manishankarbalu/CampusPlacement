class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int temp[amount+1]={0};
        temp[0]=1;
        for(int i=0;i<coins.size();i++)
           for(int j=coins[i];j<=amount;j++)
                temp[j]+=temp[j-coins[i]];
        return temp[amount];
    }
};