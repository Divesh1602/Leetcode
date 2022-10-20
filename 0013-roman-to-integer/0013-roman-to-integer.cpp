class Solution {
public:
    int value(char ch){
        int v=0;
        switch(ch){
            case 'I':
                v=1;
                break;
                
            case 'V':
                v=5;
                break;
            
            case 'X':
                v=10;
                break;
            
            case 'L':
                v=50;
                break;
            
            case 'C':
                v=100;
                break;
            
            case 'D':
                v=500;
                break;
            
            case 'M':
                v=1000;
                break;
            
            default:
                break;
        }
        return v;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int n=value(s[i]);
            if(n<value(s[i+1])){
                ans-=n;
            }
            else
                ans+=n;
        }
        return ans;
    }
};