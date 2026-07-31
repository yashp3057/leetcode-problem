class Solution {
public:
    int minimumPushes(string word) {

    unordered_map<char,int>mpp;
    
    for(int i=0; i<word.size(); i++){
        mpp[word[i]]++;
    }

    vector<pair<int,int>> v(mpp.begin(), mpp.end());

// now we make cmparater
 
 sort(v.begin(),v.end(),[](pair<int,int>a, pair<int,int>b){
    return a.second>b.second;
 });

int ans=0;

int i=0;
for(auto it: v){
 
 if(i<8){
    ans+=it.second;
 }
 else{
    ans+=((i/8+1)*it.second);
 }
i++;

}

        



return ans;


    }
};