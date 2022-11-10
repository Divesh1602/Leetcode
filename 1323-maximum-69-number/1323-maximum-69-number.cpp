class Solution {
public:
int rev(int num){
    int res=0;
    while(num!=0){
        res=res*10+num%10;
        num=num/10;
    }
    return res;
}
    int maximum69Number (int num) {
        int num1=rev(num);
        int ct=0;
        int a;
        int res=0;
        while(num1!=0){
  a=num1%10;
  if(a==6 && ct==0){
      a=9;
      ct=1;
  }
  res=res*10+a;
  num1=num1/10;
        }
        return res;
    }
};