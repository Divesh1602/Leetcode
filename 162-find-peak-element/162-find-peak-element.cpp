class Solution {
public:
    int findPeakElement(vector<int>& a) {
        	int l=0,h=a.size()-1;
        if(a.size()==1)
            return 0;
	while(l<=h){
		int mid=(l+h)/2;
        if(mid==0){
            if(a[mid]>a[1]){
                return mid;
            }
           return 1;
        }
        else if(mid==a.size()-1){
            if(a[mid]>a[mid-1])
                return mid;
            else
                return mid-1;
        }
		if(a[mid-1]<a[mid] && a[mid]>a[mid+1])
		return mid;
		if(a[mid]<=a[mid-1]){
			h=mid-1;
		}
		else
		l=mid+1;
	}
        return -1;
    }
};