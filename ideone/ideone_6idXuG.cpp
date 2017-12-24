// C++ program to find subarray with sum 
// closest to 0
#include <bits/stdc++.h>
using namespace std;

struct prefix {
	int sum;
	int index;
};

// Returns subarray with sum closest to 0. 
pair<int, int> findSubArray(int arr[], int n)
{
	pair<int,int> p;
    map<int,pair<int,int>> m;
    int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(m.find(sum)!=m.end())
			{
				p=m[sum];
				m[0]=make_pair(p.second+1,i);;
				break;      
			}
		m[sum]=make_pair(0,i);
	}

/*    auto it=m.begin();
    for(;it!=m.end();it++)
        cout<<it->first<<' '<<it->second.first<<' '<<it->second.second<<endl;
*/  
auto  it=m.begin();
    for(;it!=m.end();it++)
       if(it->first>=0)
            {
                p=it->second;
               // cout<<p.first<<' '<<p.second<<endl;
                break;
            }
    return p; 
}

// Drivers code
int main()
{
	int arr[] = { 2, 3, -4, -1, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	pair<int, int> point = findSubArray(arr, n);
	cout << "Subarray starting from ";
	cout << point.first << " to " << point.second;

	return 0;
}
