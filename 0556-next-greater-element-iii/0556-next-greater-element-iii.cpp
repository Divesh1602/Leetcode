class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        do{
            if(stol(s)>INT_MAX)
                return -1;
            else if(stol(s)>n)
                return stol(s);
        }while(next_permutation(s.begin(),s.end()));
        
        return -1;
    }
};