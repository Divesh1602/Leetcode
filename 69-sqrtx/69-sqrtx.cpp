class Solution {
public:
   long long int mySqrt(int n) {
      if(n==0)
          return 0;
     int l=1,h=n/2;
	long long int ans=1;
	while(l<=h){
		long long mid=(l+h)/2;
		
		if(mid*mid<=n){
			l=mid+1;
			ans=mid;
		}
		else
		 h=mid-1;
	
	}
	return ans;
    }
};