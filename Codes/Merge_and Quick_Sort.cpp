#include<iostream>
#include<bits/stdc++.h>

#define vi vector<int>
#define vs vector<string>
#define vc vector<char
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

using namespace std;

//  Merge Sort Algo
void merge(int ar[],int p,int q,int r){
	
	int n1=q-p+1;
	int n2=r-q;
	int ar1[100],ar2[100];
	rep(i,n1){
		ar1[i]=ar[p+i];
	}
	rep(i,n2){
		ar2[i]=ar[q+i+1];
	}
	ar1[n1]=INT_MAX;
	ar2[n2]=INT_MAX;
	int i=0,j=0,k=0;
	repi(k,p,r+1){
		if(ar1[i]<ar2[j]){
			ar[k]=ar1[i];
			i++;
		}
		else{
			ar[k]=ar2[j];
			j++;
		}
	}
}
void merge_sort(int ar[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(ar,p,q);
		merge_sort(ar,q+1,r);
		merge(ar,p,q,r);
	}
}


// Quick Sort Algo
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
 
void quick_sort(int arr[], int start, int end)
{
    if (start >= end) return;
    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}
int main(){
	int n,ar[n];
	cout<<"Enter the size for array for quick and merge sort\n";
	cin>>n;
	int ar2[n];
	cout<<"Enter value in array to check for merge sort of size n\n";
	rep(i,n){
		cin>>ar[i];
	}
	merge_sort(ar,0,n-1);
	cout<<"Implementation through Merge Sort\n";
	rep(i,n){
		cout<<ar[i]<<" ";
	}
	cout<<"Enter value in array to check for quick sort of size n\n";
	rep(i,n){
		cin>>ar2[i];
	}
	quick_sort(ar,0,n-1);
	cout<<"Implementation through Quick Sort\n";
	rep(i,n){
		cout<<ar2[i]<<" ";
	}
}


