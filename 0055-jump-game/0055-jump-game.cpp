class Solution {
public:
    bool canJump(vector<int>& nums) {
   int maxidx=false;
   for(int i=0; i<nums.size(); i++){
    
    if(i>maxidx) return false;

   maxidx=max(maxidx,nums[i]+i);    


   }

  return true;
    }
};