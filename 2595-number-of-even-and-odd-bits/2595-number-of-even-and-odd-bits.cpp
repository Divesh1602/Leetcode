class Solution {
public:
    vector<int> evenOddBit(int n) {
        string s="";
        while(n!=0){
            if(n&1==1)
                s+="1";
            else
                s+='0';
            n=n/2;
        }
       
        int even=0,odd=0;
        for(int i=0;i<s.length();i++){
            
            if(i%2==0 && s[i]=='1')
                even++;
            else if(i%2!=0 && s[i]=='1')
                odd++;
        }
        return {even,odd};
    }
};