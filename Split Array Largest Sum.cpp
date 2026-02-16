/*
Split Array Largest Sum

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

class Solution {
public:
    int f(vector<int>& nums, int mid){
        int ans=1,temp=0;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=mid) temp+=nums[i];
            else {
                ans++;
                temp=nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=nums[0],h=0,ans=0;
        for(auto it:nums) {
            l=max(l,it);
            h+=it;
        }
        while(l<=h){
            int mid=(h+l)/2;
            if(f(nums,mid)>k){
                l=mid+1;
            }
            else{
                h=mid-1;
                ans=mid;
            } 
        }
        return ans;
    }
};