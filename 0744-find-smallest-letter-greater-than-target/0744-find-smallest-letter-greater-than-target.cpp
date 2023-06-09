class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0,j=letters.size()-1;
        int ans=0;
        bool flag=false;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(letters[mid]>target){
                flag=true;
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        if(flag)
        return letters[ans];
        
        return letters[0];
    }
};