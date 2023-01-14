/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i=0;
        int j=mountainArr.length()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            int val=mountainArr.get(mid);
            if(val< mountainArr.get(mid+1) && val<target)
                i=mid+1;
            else
                j=mid;
            }
        if(mountainArr.get(j)==target)
            return j;
        
        j=mountainArr.length()-1;
        
        while(i<j){
             int mid=i+(j-i)/2+1;
            int val=mountainArr.get(mid);
            if(val< mountainArr.get(mid-1) && val<target)
                j=mid-1;
            else
                i=mid;
        }
         if(mountainArr.get(j)==target)
            return j;
        return -1;
    }
};