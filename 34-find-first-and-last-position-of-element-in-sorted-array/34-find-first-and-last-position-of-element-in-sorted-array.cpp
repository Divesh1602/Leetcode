class Solution {
public:
    vector<int> searchRange(vector<int>& a, int x) {
    vector<int> res;
        int l=0;
	int h=a.size()-1;
	while(l<=h){
	int mid=(l+h)/2;;
     if(a[mid]>x){
		h=mid-1;
	}
	else if(a[mid]<x){
		l=mid+1;
	}
	else{
		if(mid==0 || a[mid-1]!=a[mid]){
			res.push_back(mid);
            break;
		}
		else {
			h=mid-1;
		}
	}
        
    }
         if(res.size()==0){
           res.push_back(-1);
       }
        res.push_back(locu(a,x));
       
        return res;
 
    }
    int locu(vector<int>& a,int x){
           
        int n=a.size();
        int l=0;
	int h=a.size()-1;
	while(l<=h){
	int mid=(l+h)/2;;
     if(a[mid]>x){
		h=mid-1;
	}
	else if(a[mid]<x){
		l=mid+1;
	}
	else{
		if(mid==n-1 || a[mid+1]!=a[mid]){
			return mid;
		}
		else {
			l=mid+1;
		}
	}
        
    }
      return -1;
        
    }
    
};