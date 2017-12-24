class Solution {
public:
    string reverseStr(string s, int k) {
        
        int i=0,n=s.length();
        while(i<n)
        {
            int j=min(i+k-1,n-1);
            int ni=j+k+1;
            while(i<j)
                swap(s[i++],s[j--]);
            i=ni;
                
        }
        return s;
    }
};