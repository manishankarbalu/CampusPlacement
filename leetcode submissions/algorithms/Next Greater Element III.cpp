class Solution {
public:
    int nextGreaterElement(int n) {
     
        string d=to_string(n);
        next_permutation(begin(d),end(d));
        auto r=stoll(d);
        return (r<=n || r>INT_MAX)?-1:r;
    }
};