class Solution {
public:
    string frequencySort(string s) {
   
    unordered_map<char,int>freq;
    
    for(int i=0; i<s.size(); i++){
        freq[s[i]]++;
    }

    vector<vector<char>>bucket(s.size()+1);
     
     for(auto it:freq){
        bucket[it.second].push_back(it.first);

     }
    string ans="";
    for(int i=s.size(); i>=0; i--){
        
        for(char c:bucket[i]){
    ans.append(i,c);
        }

    }

 return ans;

    }
};