class Solution {
public:
   bool isvalid(int mid,vector<int>& citations){
     int count=0;
   for(int i=0; i<citations.size(); i++){
    if(citations[i]>=mid){
        count++;

    }
     

   }
   if(count>=mid) return true;

 return false;

   }


    int hIndex(vector<int>& citations) {
        sort( citations.begin(), citations.end());
        int low=1;
        int high= citations.size();
         int ans=0;
        while(low<=high){
            int mid=(low+high)/2; 
          
            if(isvalid(mid,citations)){
                low=mid+1;
              ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};