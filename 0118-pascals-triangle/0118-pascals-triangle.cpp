class Solution {
public:
  
 vector<int>g(int row){
 vector<int>temp;
 int ans=1;
 temp.push_back(ans);

 for(int i=1; i<row; i++){
   
   ans=ans*(row-i);
   ans=ans/i;
   temp.push_back(ans);

 }

return temp;



 }



    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
     
     for(int i=1; i<=numRows; i++){
        ans.push_back(g(i));
     }
  
  return ans;
    }
};