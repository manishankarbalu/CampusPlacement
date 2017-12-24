class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> maps={
                                        {'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}
                                        
                                      };
                                      
        int sum=maps[s.back()];
        for(int i=s.size()-2;i>=0;--i)
        {
            if(maps[s[i]]<maps[s[i+1]])
            {
                sum-=maps[s[i]];
            }
            else
            {
                sum+=maps[s[i]];
            }
        }
        return sum;
    }
};