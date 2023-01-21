class Solution {
public:
    vector<string> ans;
    
    bool valid( string tok ){
        if( tok.size() > 3 || stoi(tok) > 255 ) return false;
        return true;
    }
    void validip( string s , string tok , string ip , int i , int d ){
        int n = s.size();
        if( tok.size() > 1 && tok[0] == '0' ) return ;
        if( d == 4 && ( tok.size() || i != n ) ) return ;
        if( i == n ){
            if( tok.size() ){ ip += tok; d++; }
            if( d == 4 ) ans.push_back(ip);
            return;
        } 
        string nt = ""; nt += s[i] ;
        if( tok.size() ) validip(s,nt,ip+tok+".",i+1,d+1);
        if( valid(tok+s[i]) ) validip(s,tok+s[i],ip,i+1,d);
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size() ;
        if( n > 12 ) return {}; 
        validip(s,"","",0,0);
        return ans;
    }
};