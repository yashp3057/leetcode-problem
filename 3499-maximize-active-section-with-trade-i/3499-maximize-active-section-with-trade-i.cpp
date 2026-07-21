class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int count1=0;
        for(int i=0; i<s.size(); i++){
         if(s[i]=='1'){
            count1++;
         }
        }

     vector<int>zero;
     int i=0;
     while(i<n){
      
      if(s[i]=='0'){
    int start=i;

    while(i<n && s[i]=='0'){
        i++;
    }
    zero.push_back(i-start);



      }
      else{
        i++;
      }



     }
      
    
    int maxsumpair=0;
    for(int i=1; i<zero.size(); i++){
        
        maxsumpair=max(maxsumpair,zero[i-1]+zero[i]);
    }

    
    return maxsumpair+count1;
    
    }
};