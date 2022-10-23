// https://codeforces.com/problemset/problem/1741/D
#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
#define int long long
const int N = 2e5+5;
const int mod = 1e9+7;
main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1 ; i<=n ; i++) cin>>arr[i];
        int operations = 0;
        for(int i=1 ; i<=n ; i*=2) // determining the subsegments of size i that is going from the top of tree
        {
            int max1;
            int max2;
            int counter = 1;
            for(int j=1 ; j<=n ; j++)
            {
                if(j==1)
                {
                    max1 = arr[j];
                    max2 = 0;
                }
                else if((j<=counter*i)) // first subsegment
                {
                    max1 = max(max1,arr[j]);
                }
                else if(j>counter*i && j<(counter+1)*i){ 
                    max2 = max(max2,arr[j]);
                }
                else if(j==(counter+1)*i) // the second segment is here and we have to check if maximum of first segment is greater than we have to swap that will increase the operations by 1
                {
                    counter+=2;
                    max2 = max(max2,arr[j]);
                    if(max1 > max2 ) operations++;
                    
                    if(abs(max1-max2)/i == 1){}   // -1 condition if the difference between them isn't atmost 1 then we cannot sort no matter what
                    else{
                        operations = -1;
                        break;
                    }
                    max1=0; // reinitializing it with 0 
                    max2=0;
                } 
            }
            if(operations==-1) break;
        }
        cout<<operations<<"\n";
    }
}