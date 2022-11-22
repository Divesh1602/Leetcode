class Solution {
public:
    bool search(vector<int>& a, int x) {
         int l=0,h=a.size()-1;
        sort(a.begin(),a.end());
        while(l<=h){
		int mid=(l+h)/2;
		if(a[mid]==x)
		  return true;
		if(a[mid]>x)
            h=mid-1;
         else
                l=mid+1;
		
}
	return false;
    }
};