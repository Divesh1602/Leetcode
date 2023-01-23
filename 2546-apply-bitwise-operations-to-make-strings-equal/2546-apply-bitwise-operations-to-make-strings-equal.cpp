class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        int zero_s=0,zero_target=0,one_s=0,one_target=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                zero_s++;
            else
                one_s++;
            if(target[i]=='0')
                zero_target++;
            else
                one_target++;
        }
       if(one_s>0 && one_target>0)
           return true;
        else if(zero_s==0 && zero_target==0 || one_target==0 && one_s==0)
            return (s==target);
        
        return false;
    }
};