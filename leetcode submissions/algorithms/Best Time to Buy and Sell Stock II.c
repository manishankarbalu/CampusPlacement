int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxProfit(int* prices, int pricesSize) {
     int res=0;
     for(int i=1;i<pricesSize;i++)
         res+=max(prices[i]-prices[i-1],0);
     return res;
    
}