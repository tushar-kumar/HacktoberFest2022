#include<iostream>
#include<string>
using namespace std;

int countEncodings(string str){
   int n = str.size();
   if(n>0) if(str[0] == '0') return 0; 
   int dp[n] = {0};
   dp[0] = 1;
   for(int i = 1; i < n; i++){
      if(str[i-1] == '0' && str[i] == '0'){
        dp[i] = 0;
      }
      else if(str[i-1] == '0' && str[i] != '0'){
          dp[i] = dp[i-1];
      }
      else if(str[i-1] != '0' && str[i] == '0'){
        if(str[i-1] == '1' || str[i-1] == '2'){
            dp[i] = (i>=2 ?dp[i-2] : 1);
        }
      }
      else{
        dp[i] = dp[i-1];
        if(stoi(str.substr(i-1,2)) <= 26){
            dp[i] += (i>=2 ?dp[i-2] : 1);
        }
      }
   }
   return dp[n-1];
}

int main(){
    string str;
    cin>>str;
    cout<<countEncodings(str)<<"\n";
    return 0;
}