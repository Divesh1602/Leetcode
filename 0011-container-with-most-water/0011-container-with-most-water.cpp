class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0,j=height.size()-1;
        int ans=0;
        while(i<j){
            int l=height[i];
            int h=height[j];
            int cal=(j-i)*min(l,h);
            ans=max(ans,cal);
            
            if(l<h)
                i++;
            else 
                j--;
            
        }
        return ans;
    }
};