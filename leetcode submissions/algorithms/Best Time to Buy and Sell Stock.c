int maxProfit(int* arr, int n) {
    if(n<2) return 0;
    int minEle=arr[0],maxDiff=arr[1]-arr[0];
        for(int i=1;i<n;i++)
        {
            if(maxDiff<arr[i]-minEle)
               maxDiff=arr[i]-minEle;
            if(minEle>arr[i])
               minEle=arr[i];
        }
        return (maxDiff>0)?maxDiff:0;
}