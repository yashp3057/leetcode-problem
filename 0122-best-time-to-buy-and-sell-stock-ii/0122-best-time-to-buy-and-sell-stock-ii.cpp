class Solution {
public:
   int helper(vector<int>&prices,int idx,int buy,int n,vector<vector<int>>&dp){
     
     if(idx==n) return 0;
    int profit=0;

    if(dp[idx][buy]!=-1){
        return dp[idx][buy];
    }


     if(buy==1){
     
    profit=max(-prices[idx]+helper(prices,idx+1,0,n,dp) , 0+helper(prices,idx+1,1,n,dp));

     }
     else{
        profit=max(prices[idx]+helper(prices,idx+1,1,n,dp) , 0+helper(prices,idx+1,0,n,dp));
     }

return dp[idx][buy]=profit;

   }




    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,1,n,dp);
    }
};