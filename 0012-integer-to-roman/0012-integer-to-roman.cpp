class Solution {
public:
    string intToRoman(int num) {
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        for(int i=0;i<13;i++){
            while(num>=value[i]){
                ans+=symbol[i];
                num-=value[i];
            }
        }
        return ans;
    }
};