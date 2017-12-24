class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' || c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U' );
    }
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            while(!isVowel(s[i]) && i<=j)i++;
            while(!isVowel(s[j]) && i<=j)j--;
            if(i<=j)
            {swap(s[i++],s[j--]);}
        }
     return s;       
    }
};