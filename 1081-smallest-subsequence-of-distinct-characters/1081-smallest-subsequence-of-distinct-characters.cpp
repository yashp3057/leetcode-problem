class Solution {
public:
    string smallestSubsequence(string s) {
    
 vector<bool>vis(26,false);
 vector<char>frq(26,0);

 stack<char>st;
 for(int i=0; i<s.size(); i++){
     frq[s[i]-'a']++;
 }

 for(int i=0; i<s.size(); i++){

     char ch=s[i];
     frq[ch-'a']--;

     if(vis[ch-'a']==true) continue;

     while(!st.empty() && st.top()>ch && frq[st.top()-'a']>0){
        vis[st.top()-'a']=false;
        st.pop();

     }

     st.push(s[i]);
    vis[ch-'a']=true;


 }
  string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;


    }
};