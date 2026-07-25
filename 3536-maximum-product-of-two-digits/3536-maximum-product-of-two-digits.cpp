class Solution {
public:
    int maxProduct(int n) {
        
     vector<int>nums;
     while(n>0){
        int k=n%10;
        nums.push_back(k);
        n=n/10;
     }

     sort(nums.begin(),nums.end());
     return nums[nums.size()-1]*nums[nums.size()-2];

    }
};