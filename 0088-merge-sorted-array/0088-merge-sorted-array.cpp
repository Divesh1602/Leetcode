class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
return;
if(m==0)
{
for(int i=0;i<n;i++)
{
nums1[i]=nums2[i];
}
return;
}
for(int i=m-1;i>=0;i--)
{
nums1[i+n]=nums1[i];
}
int i=n,j=0;
int k=0;
while(i<m+n && j<n)
{
if(nums1[i]<=nums2[j])
{
nums1[k++]=nums1[i++];
}
else
{
nums1[k++]=nums2[j++];
}
}
while(i<m+n)
{
nums1[k++]=nums1[i++];
}
while(j<n)
{
nums1[k++]=nums2[j++];
}
    }
};