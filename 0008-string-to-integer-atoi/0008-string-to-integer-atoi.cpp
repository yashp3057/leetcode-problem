class Solution {
public:
    int myAtoi(string s) {
      int n=s.size();
      int i=0; 


      while(i<n && s[i]==' '){
        i++;
      }  

      int sign=1;
     if(i<n && ((s[i]=='+') || s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        i++;
      }

   long long digit=0;
      
      while(i<n && isdigit(s[i])){
        int num=s[i]-'0';
        digit=digit*10+num;
        i++;

      if(digit*sign>INT_MAX) return INT_MAX;
      if(digit*sign<INT_MIN) return INT_MIN;
      } 
        return sign*digit;
    }
};