#include<iostream>
using namespace std;
int maxSumSubArray(int arr[] , int n){
    int currentSum = arr[0];
    int maxSum = arr[0];
    for(int i=1; i<n; i++){
        if(currentSum >= 0){
            currentSum += arr[i];
        }
        else currentSum = arr[i];
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
}
int main(){
    int arr[] = {4,3,-2,6,7,-10,-10,4,5,9,-3,4,7,-18,2,9,3,-2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumSubArray(arr,n)<<"\n";
    return 0;
}