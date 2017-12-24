class Solution {
int max=256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int visited[max];
        memset(visited,-1,sizeof(visited));
        int curlen=1,maxlen=1,prev=0,i;
        int n=s.length();
        if(n==0) return 0;
        visited[s[0]]=0;
        for(int i=1;i<n;i++)
        {
            prev=visited[s[i]];
            
            if(prev==-1 || i-curlen>prev)
              curlen++;
            else
            {
                maxlen=(maxlen>curlen)?maxlen:curlen;
                curlen=i-prev;
            }
            visited[s[i]]=i;
        }
        maxlen=(maxlen>curlen)?maxlen:curlen;
        return maxlen;
        
    }
};