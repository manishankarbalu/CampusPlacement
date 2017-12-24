#include <iostream>
#include <vector>
using namespace std;
int maxValue1(vector<int> price)
{
        int maxi[price.size()+1]={0};
        for(int i=1; i <= price.size(); i++){
            maxi[i] = price[i-1];
        }
        for(int i=1 ; i <= price.size(); i++){
            for(int j=1; j < i ; j++){
                maxi[i] = max(maxi[i], maxi[i-j] + maxi[j]);
            }
        }
        for(int i: maxi)
           cout<<i<<' ';
        cout<<endl;
        return maxi[price.size()];
}
int main() {
	// your code goes here
vector<int> arr={3, 5, 8, 9, 10, 17, 17, 20};
	cout<<maxValue1(arr);
	return 0;
}