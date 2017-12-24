class Solution {
public:
    
    void reverse(string &s,int st,int en)
    {
        while(st<en)
        {
            char temp=s[st];
            s[st++]=s[en];
            s[en--]=temp;
        }
    }
    
    string reverseWords(string s) {
        
        int st=-1,i=0,n=s.length();
        
        while(i<n)
        {
            if((st==-1) && (s[i])!=' ' )
                st=i;
            if((st!=-1) && (s[i+1]==' ' || s[i+1]=='\0'))
            {
                reverse(s,st,i);
                st=-1;
            }
          i++;
        }
        return s;
    }
};