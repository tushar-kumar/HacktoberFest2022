#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
        vector<int> mxl;
        vector<int> mxr;
        int n = height.size();
        mxl.push_back(height[0]);
        for(int i=1;i<height.size();i++)
        {
            int temp = max(mxl.back(), height[i]);
            mxl.push_back(temp);
        }
        mxr.push_back(height[n-1]);
        for(int i=height.size()-2;i>=0;i--)
        {
            int temp = max(mxr.back(), height[i]);
            mxr.push_back(temp);
        }
        reverse(mxr.begin(),mxr.end());
        
        
        int sum = 0;
        
        for(int i=0;i<height.size();i++)
        {
            int mj = min(mxl[i],mxr[i]);
            sum += mj - height[i];
        }
        return sum;
    }
int main(){

    vector<int> bars = {0,1,0,2,1,0,1,3,2,1,2,1};
    int watertrapped = trap(bars);

    cout<<"Total amount of water trapped: "<<watertrapped;
}