class Solution {
public:
    int reverse(int x) {
        long long int rev=0;
        while(x)
        {
            rev=(rev*10)+(x%10);
            x=x/10;
        }
        //rev=(neg==1)?rev*-1:rev;
        return (rev>INT_MAX || rev<INT_MIN)?0:(int)rev;
    }
};