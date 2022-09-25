class Solution {
public:
    int search(vector<int>& a, int x) {
        	int l=0;
	int h=a.size()-1;
	while(l<=h){
	int mid=(l+h)/2;
	if(a[mid]==x)
	return mid;
	else if(a[mid]>x){
		h=mid-1;
	}
	else if(a[mid]<x){
		l=mid+1;
	}
}
	return -1;
        
    }
};