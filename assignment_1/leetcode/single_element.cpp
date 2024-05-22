class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        long long int len = nums.size();
        if(len==1) return nums[0];
        long long int n = len/2;
        long long int l=0,r=len-1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid==0) return nums[0];
            if(mid==len-1) return nums[len-1];
            if(nums[mid]!= nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid+1]){
                if (n%2){
                    r=mid-1;
                    n/=2;
                }
                else{
                    l=mid+2;
                    n = n/2 - 1;
                }
            }
            else{
                if(n%2){
                    l=mid+1;
                    n/=2;
                }
                else{
                    r=mid-2;
                    n = n/2 - 1;
                }
            }
        }
return -1;
    }
};
