class Solution {
public:
    string predictPartyVictory(string a) {
        int r=0,d=0,n=a.size();
        bool lastr=0,lastd=0;
        queue<char> qu;
        char ans;
        for(auto i:a) {    
            qu.push(i);
        }
        int i=0;
        bool flag=1;
        while(true) {
            char x= qu.front();
            
            if(x=='R' && d) {
                qu.pop();
                --d;
                flag=0;
            }
            else if(x=='D' && r) {
                qu.pop();
                --r;
                flag=0;
            }
            else if(x=='R') {
                ++r;
                qu.pop();
                qu.push(x);
            }
            else {
                ++d;
                qu.pop();
                qu.push(x);
            }
             i++;
            if(i==n) {
                n = qu.size();
                i=0;
                if(flag) {
                    ans = qu.front();
                    break;
                }
                flag=1;
            }
            
        }
        return (ans=='R')?"Radiant":"Dire";
    }
}; 