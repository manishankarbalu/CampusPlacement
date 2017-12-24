class Solution {
public:
    string convert(string s, int n) {
        if(n<=1)
            return s;
        vector<string> v(n,"");int step=0,row=0;
        for(int i=0;i<s.length();i++)
        {
            v[row].push_back(s[i]);
            
            if(row==0)
                step=1;
            else
                 if(row==n-1)
                     step=-1;
            row+=step;
        }
        
        string s1="";
        for(string i : v)
             s1=s1+i;
        return s1;
    }
};