#include<bits/stdc++.h>
using namespace std;

// m is maximum of number zeroes allowed to flip
// n is size of array
void findZeroes(int arr[], int n, int m)
{

  int s[n];int count=0;
  for(int i=0;i<n;i++)
  {
      if(arr[i]==1)
          {s[i]=0;
           count++;
          }
      else
         if(arr[i]==0)
         {
             s[i]=count;
             count=0;
         }
  }
  count=0;
for(int i=n-1;i>=0;i--)
  {
      if(arr[i]==1)
          {s[i]=0;
           count++;
          }
      else
         if(arr[i]==0)
         {
             s[i]+=count;
             count=0;
         }
  }
  int mx=INT_MIN,ind=0;
  for(int j=0;j<m;j++)
  {
      for(int i=0;i<n;i++)
      {
          if(mx<s[i])
            {
                mx=s[i];
                ind=i;
            }
      }
      cout<<ind<<'\t';
  }
  

}

// Driver program
int main()
{
int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
int m = 2;
int n = sizeof(arr)/sizeof(arr[0]);
cout << "Indexes of zeroes to be flipped are ";
findZeroes(arr, n, m);
return 0;
}
