class Solution {
public:

    int helper(vector<int>&nums, int idx, int n, vector<int>&dp){


     if(idx>n) return 0;
     if(dp[idx]!=-1) return dp[idx];

     int take=nums[idx]+helper(nums,idx+2,n,dp);
     int nottake=0+helper(nums,idx+1,n,dp);

 return dp[idx]=max(take,nottake);


    }
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return nums[0];
      vector<int>dp1(n,-1);
      int case1=helper(nums, 0,n-2,dp1);
      vector<int>dp2(n,-1);
      int case2=helper(nums,1,n-1,dp2);

return max(case1,case2);
    }
};