class Solution {
public:
    string reverseString(string s) {
       int j=s.length()-1;
        int i=0;
        while(i<=j)
        {
            swap(s[i++],s[j--]);
        }
        return s;
    }
};