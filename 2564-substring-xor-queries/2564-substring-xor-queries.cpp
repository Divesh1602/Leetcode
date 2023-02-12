class Solution {
public:

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
         vector<vector<int>> ans;
         unordered_map<long long,pair<int,int>>m;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!m.count(0)) m[0]=make_pair(i,i);
                continue;
            }
            long long num=0;
            for(int j=i;j<=min(i+32,n-1);j++){
                num = (num << 1) + (s[j] - '0');
                if(!m.count(num)) m[num] = make_pair(i,j);                
            }
        }
        for(auto a:queries){
            int find=a[0]^a[1];
           if(m.count(find))
               ans.push_back({m[find].first,m[find].second});
            else
                ans.push_back({-1,-1});
        }
         return ans;
       
    }
        
    
};