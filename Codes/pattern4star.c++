#include <iostream>
using namespace std;
int main (){
      int n ;
    cout << "please input the number for the following pattern\n";
    cin >> n ;
    
     int row  = 1 ;
     while (row <= n ){
        int LogicForSpace = n - row ;
        while (LogicForSpace){
              cout << " " ;
              LogicForSpace--;  
        }
        
        int  col = 1 ;
        while (col<= row ){
             cout<<"*";
             col = col + 1;
        }
        cout << "\n";
        row = row + 1 ;
     }
}