class Solution {
public:
int gcd(int a,int b){
 int ans=1;   
int mini=min(a,b);
for(int i=2; i<=mini; i++){

 if(a%i==0 && b%i==0){
   
   while(a%i==0 && b%i==0){
    a=a/i;
    b=b/i;
    ans=ans*i;

   }
     

 }


}

return ans;

}




int gcdOfOddEvenSums(int n) {
        
  int oddsum=0;
  int evensum=0;
  for(int i=1; i<=2*n; i++){
  if(i%2==0){
   evensum+=i;
  }
  else{
    oddsum+=i;
  }

  }

 return gcd(evensum,oddsum);

    }
};