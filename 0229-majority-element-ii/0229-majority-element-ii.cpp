class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { 
int n=nums.size();
 int count1=0;
 int count2=0;
 int ele1=0;
 int ele2=0;

 for(int i=0; i<nums.size(); i++){

 if(nums[i]==ele1){
    count1++;
 }
 else if(nums[i]==ele2){
    count2++;
 }
 else if(count1==0){
    count1=1;
    ele1=nums[i];
 }
else if(count2==0){
    count2=1;
    ele2=nums[i];
}
else{
    count1--;
    count2--;
}




 }

count1=0;
count2=0;


 for(int i=0; i<nums.size(); i++){
    if(nums[i]==ele1){
        count1++;
    }
    else if(nums[i]==ele2){
        count2++;
    }
 }

vector<int>ans;
if(count1>n/3){
    ans.push_back(ele1);
}

if(count2>n/3){
    ans.push_back(ele2);
}


return ans;

    }
};