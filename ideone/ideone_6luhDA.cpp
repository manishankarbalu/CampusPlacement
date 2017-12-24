    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    	int n=3,i;
        int arr[]={9,2,1},inv[n];
       
        vector<int> v;
        v.push_back(arr[n-1]);
        inv[n-1]=0;
        for(i=n-2;i>=0;i--){
            auto  it = lower_bound(v.begin(),v.end(),arr[i]);
            
            inv[i]=it-v.begin();
            cout<<v.size()<<' '<<*it<<' '<<inv[i]<<' '<<*v.begin()<<endl;
            v.insert(it,arr[i]);
            for(int j : v)
              cout<<j<<' ';
              cout<<endl;
        }
        int sum=0;
        for(i=0;i<n;i++){
            sum = sum + inv[i] ;
        }
        cout <<endl<< sum<<endl;
    
        return 0;
    }