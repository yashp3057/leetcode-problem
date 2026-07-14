class Disjointset{
    public:
    vector<int>parents,size;

    Disjointset(int n){
    parents.resize(n);
    size.resize(n,1);
    for(int i=0; i<n; i++){
        parents[i]=i;
    }
    }
 
 int finduparents(int node){
   
   if(parents[node]==node) return node;
   return finduparents(parents[node]);

 }

 void unionbysize(int u,int v){
 
 int up=finduparents(u);
 int vp=finduparents(v);

 if(up==vp) return;
 if(size[up]<size[vp]){
    parents[up]=vp;
    size[vp]+=size[up];
 }
 else{
    parents[vp]=up;
    size[up]+=size[vp];
 }


 }



};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
   int n=accounts.size();     
   unordered_map<string,int>mapmailnode;
   Disjointset ds(n);
// check which string is common or not 
   for(int i=0; i<n; i++){
    for(int j=1; j<accounts[i].size(); j++){
     string mail=accounts[i][j];

     if(mapmailnode.find(mail)==mapmailnode.end()){
      mapmailnode[mail]=i;
     }
     else{ 
        ds.unionbysize(mapmailnode[mail],i); // in this portion we union of this 
     }

    }
   }
// merged common  string

vector<vector<string>> merge(n);
   
   for(auto it:mapmailnode){
    string mail=it.first;
    int node=ds.finduparents(it.second);
    merge[node].push_back(mail);

   }
  vector<vector<string>>ans;
   // now in this portin we add first name in to the string we dont included above part
   for(int i=0; i<n; i++){

   if(merge[i].size()==0) continue;
   sort(merge[i].begin(), merge[i].end());
   string name=accounts[i][0];
   vector<string>temp;
   temp.push_back(name);
   for(auto it: merge[i]){
    temp.push_back(it);
   }
   ans.push_back(temp);

   }

return ans;
    }
};