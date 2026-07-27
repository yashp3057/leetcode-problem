class Solution {
public:
    string reverseWords(string s) {

  vector<string>word;

  for(int i=0; i<s.size(); i++){
  
  if(s[i]==' ')continue;
  string small="";

  while(i<s.size() && s[i]!=' '){
    small+=s[i];
    i++;
  }
  word.push_back(small);


  } 
  string ans=""; 
  reverse(word.begin(),word.end());
  for(int i=0; i<word.size(); i++){
    ans+=word[i];
    if(i!=word.size()-1){
        ans+=" ";
    }

  }      
  return ans;

    }
};